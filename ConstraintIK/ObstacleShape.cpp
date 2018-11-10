#include "ObstacleShape.h"

#include <list>
#include <vector>
#include <string>
#include <fstream>

#include <cnoid/MessageView>
#include <cnoid/ItemTreeView>

#include "../Grasp/VectorMath.h"
#include "../Grasp/DrawUtility.h"
#include "../GeometryHandler/GeometryHandle.h"

#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
#define NODE_TYPE type()
#else
#define NODE_TYPE nodeType()
#include "../Grasp/ColdetConverter.h"
#endif

using namespace std;
using namespace cnoid;
using namespace grasp;

void ObstacleShapeDrawer::show() const {
	PlanBase* tc = PlanBase::instance();

	ObstacleParameterReader opr;
  if (tc->targetArmFinger != NULL) {
		opr.readRobotYamlFile(tc->body(), tc->targetArmFinger->arm);
  }
  opr.readEnvYamlFiles();
  ObstacleShapeVec obstacle_shapes = opr.getObstacleShapes();
  ArmShapeVec arm_shapes = opr.getArmShapes();

	DrawUtility* draw = DrawUtility::instance();
  draw->clear();
  Vector3 color = Vector3(0.5, 0, 0);
  double alpha = 0.2;

  for (ObstacleShapeVecConstIterator vi = obstacle_shapes.begin(); vi != obstacle_shapes.end(); ++vi) {
    ObstacleShape* obj = (*vi);
    obj->updatePos();
    draw->ellipsoids.push_back(Ellipsoid(obj->getPos(), obj->getR(), obj->getRadius(), color, alpha));
  }

  for (ArmShapeVecConstIterator vi = arm_shapes.begin(); vi != arm_shapes.end(); ++vi) {
    ArmShape* obj = (*vi);
    obj->updatePos();
    draw->ellipsoids.push_back(Ellipsoid(obj->getPos(), obj->getR(), obj->getRadius(), color, alpha));
  }

  draw->displayEllipsoids();
}

ObstacleShapeHandler::ObstacleShapeHandler() :
os(MessageView::mainInstance()->cout()) , security_distance(0.01), effective_distance(0.2), xi(0.1), ellip_radius(0.005) {
  num_cluster = 1;
  vol_ratio_threshold = 0.2;
  scale = 1.0;
  color = Vector3(0.5, 0, 0);
  alpha = 0.4;
}

ObstacleShapeHandler::~ObstacleShapeHandler() {
  // do nothing
}

ObstacleShapeHandler* ObstacleShapeHandler::instance(ObstacleShapeHandler *osh) {
  static ObstacleShapeHandler* instance = (osh) ? osh : new ObstacleShapeHandler();
  if (osh) instance = osh;
  return instance;
}

/**
* Display obstacle shapes and output obstacle information to the file.
* @param[in] is_boundingbox true: place ellipsoids at bounding box edges. false: place ellipsoids which is generated by ellipsoidal approximation of the target object.
* @param[in] is_output      output obstacle ellipsoids information if true.
*/
void ObstacleShapeHandler::showObstacleShapes(bool is_boundingbox, bool is_output) {
  tc = PlanBase::instance();

  if (tc == NULL) {
    os << "implmentation error: you have to call initial()" << endl;
  }

  if ( !tc->targetObject ) {
    os << "Please select traget object" << endl;
    return;
  }

#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
  ObjectShape* obj = createObjectShape(
    tc->targetObject->bodyItemObject->body()->link(0)->coldetModel());
#else
  ObjectShape* obj = createObjectShape(
    tc->targetObject->bodyItemObject->body()->link(0)->collisionShape());
#endif

  if (is_boundingbox) {
    addObstacleBoundingboxShapes(obj);
  } else {
    addObstacleEllipsoidShapes(obj);
  }

  if (is_output) {
    writeObstacleShapes();
  }

	displayObstacleShapes();

  delete obj;
}

/**
* Generate obstacle ellipsoids of Object @c obj
* @param[in] obj target ObjectShape pointer
*/
void ObstacleShapeHandler::addObstacleEllipsoidShapes(ObjectShape* obj) {
  ellipsoids.clear();
  vector<Matrix3> qrot;
  vector<Vector3> qcenter;
  vector<Vector3> qradius;
  vector<double> qscale;

  obj->getClusterQuadParameters(num_cluster, &qrot, &qcenter, &qradius, &qscale, vol_ratio_threshold, scale);

  for (size_t i = 0; i < qcenter.size(); i++) {
    EllipsoidShape e;
    e.setP(qcenter[i]);
    e.setR(qrot[i]);
    Vector3 radius = (qradius[i]/qscale[i]).cwiseSqrt().cwiseInverse();
    e.setRadius(radius);
    ellipsoids.push_back(e);
  }
}

/**
* Generate obstacle ellipsoids which is placed at bounding box edges.
* @param[in] obj target ObjectShape pointer
*/
void ObstacleShapeHandler::addObstacleBoundingboxShapes(ObjectShape* obj) {
  ellipsoids.clear();
  vector<Vector3> edges;
  vector<Vector3> centers;
  vector<Matrix3> rots;

  obj->getClusterParameters(num_cluster, &edges, &centers, &rots, vol_ratio_threshold, scale);

  for (size_t i = 0; i < edges.size(); i++) {
    vector<Vector3> center_list;
    vector<Vector3> length_list;

    for (int a1 = 0; a1 < 3; a1++) {
      int a2 = (a1 + 1) % 3;
      int a3 = (a1 + 2) % 3;
      Vector3 length = ellip_radius * Vector3::Ones();
      length[a1] = edges[i][a1]/2.0;
      if (edges[i][a1] > ellip_radius) {
        Vector3 center;
        center[a1] = 0; center[a2] = edges[i][a2]/2.0; center[a3] = edges[i][a3]/2.0;
        center_list.push_back(center);
        length_list.push_back(length);
        if (edges[i][a2] > ellip_radius) {
          center[a1] = 0; center[a2] = -edges[i][a2]/2.0; center[a3] = edges[i][a3]/2.0;
          center_list.push_back(center);
          length_list.push_back(length);
        }
        if (edges[i][a3] > ellip_radius) {
          center[a1] = 0; center[a2] = edges[i][a2]/2.0; center[a3] = -edges[i][a3]/2.0;
          center_list.push_back(center);
          length_list.push_back(length);
          if (edges[i][a2] > ellip_radius) {
            center[a1] = 0; center[a2] = -edges[i][a2]/2.0; center[a3] = -edges[i][a3]/2.0;
            center_list.push_back(center);
            length_list.push_back(length);
          }
        }
      }
    }

    for (size_t j = 0; j < center_list.size(); j++) {
      EllipsoidShape e;
      e.setP(centers[i] + rots[i] * center_list[j]);
      e.setR(rots[i]);
      e.setRadius(length_list[j]);
      ellipsoids.push_back(e);
    }
  }

  removeDuplicatedEllipsoids();
}

/**
* Remove duplicated ellisoids.
*/
void ObstacleShapeHandler::removeDuplicatedEllipsoids() {
  for (vector<EllipsoidShape>::iterator vi = ellipsoids.begin(); vi != ellipsoids.end();) {
    EllipsoidShape target_e = *vi;
    bool is_same = false;
    for (vector<EllipsoidShape>::iterator vi2 = vi + 1; vi2 != ellipsoids.end(); ++vi2) {
      EllipsoidShape comp_e = *vi2;
      double dist = norm2(target_e.getP() - comp_e.getP());
      Vector3 target_len = target_e.getR() * target_e.getRadius();
      Vector3 comp_len = comp_e.getR() * comp_e.getRadius();
      double len_diff = fabs(norm2(target_len)-norm2(comp_len));
      double dir = fabs(dot(target_len.cwiseAbs(), comp_len.cwiseAbs()) / (norm2(target_len) * norm2(comp_len)));
      if (dist < 0.01 && len_diff < 0.01 && dir > 0.99) {
        is_same = true;
        break;
      }
    }
    if (is_same) {
      vi = ellipsoids.erase(vi);
    } else {
      ++vi;
    }
  }
}

/**
* Output obstacle shape info to a yaml file.
*/
void ObstacleShapeHandler::writeObstacleShapes() const {
  string filename = tc->targetObject->name() + ".yaml";
  ofstream fout;
  fout.open(filename.c_str());

#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
  fout << "modelFile: " << tc->targetObject->bodyItemObject->lastAccessedFilePath() << endl;
#else
  fout << "modelFile: " << tc->targetObject->bodyItemObject->filePath() << endl;
#endif
  fout << endl;

  fout << "collisionShape:" << endl;

  for (size_t i = 0; i < ellipsoids.size(); i++) {
    EllipsoidShape e = ellipsoids[i];
    Vector3 rpy = rpyFromRot(e.getR());
    Vector3 p = e.getP();
    fout << "  -" << endl;
    fout << "    center: [" << p[0] << " , " << p[1] << " , " << p[2] << "]" << endl;
    fout << "    rpy: [" << rpy[0] << " , " << rpy[1] << " , " << rpy[2] << "]" << endl;
    fout << "    length: [" << e.a() << " , " << e.b() << " , " << e.c() << "]" << endl;
    fout << "    security_distance: " << security_distance << endl;
    fout << "    effective_distance: " << effective_distance << endl;
    fout << "    xi: " << xi << endl;
  }
  fout.close();
}

/**
* Display obstacle shapes.
*/
void ObstacleShapeHandler::displayObstacleShapes() const {
	Vector3 obj_p = tc->targetObject->object->p();
  Matrix3 obj_R = tc->targetObject->object->R();

	DrawUtility* draw = DrawUtility::instance();
	draw->clear();

	for (vector<EllipsoidShape>::const_iterator vi = ellipsoids.begin(); vi != ellipsoids.end(); ++vi) {
    EllipsoidShape e = *vi;
    Vector3 temp_center = obj_p + obj_R * e.getP();
    Vector3 length = e.getRadius();
    draw->ellipsoids.push_back(Ellipsoid(temp_center, obj_R * e.getR(), length, color, alpha));
  }

	draw->displayEllipsoids();
}

/**
* Create ObjectShape from CldetModelPtr.
* @param[in] c ColdetModelPtr of target object
* @return ObjectShape pointer of target object
*/
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
ObjectShape* ObstacleShapeHandler::createObjectShape(ColdetModelPtr c) const {
  vector<double> vertex;
  float tx, ty, tz;
  for (int k = 0; k < c->getNumVertices(); k++) {
    c->getVertex(k, tx, ty, tz);
    vertex.push_back(tx);
    vertex.push_back(ty);
    vertex.push_back(tz);
  }
  vector<int> crd;
  int t1, t2, t3;
  for (int k = 0; k < c->getNumTriangles(); k++) {
    c->getTriangle(k, t1, t2, t3);
    crd.push_back(t1);
    crd.push_back(t2);
    crd.push_back(t3);
    crd.push_back(-1);
  }

  return new ObjectShape(vertex, crd);
}
#else
ObjectShape* ObstacleShapeHandler::createObjectShape(SgNode* c) const {

  cnoid::SgMeshPtr mesh = ColdetConverter::ExtractMesh(c);
  cnoid::SgVertexArrayPtr vertices = mesh->vertices();
  cnoid::SgIndexArray indices = mesh->triangleVertices();

  vector<double> vertex;
  for(int k = 0; k < vertices->size(); k++){
    cnoid::Vector3f vec = vertices->at(k);
    vertex.push_back( vec[0] );
    vertex.push_back( vec[1] );
    vertex.push_back( vec[2] );
  }
  vector<int> crd;
  for(int k = 0; k < mesh->numTriangles(); k++){
    crd.push_back( indices[k*3] );
    crd.push_back( indices[k*3+1] );
    crd.push_back( indices[k*3+2] );
    crd.push_back( -1 );
  }
  return new ObjectShape(vertex,crd);
}
#endif


ObstacleParameterReader::ObstacleParameterReader() {
  arm_shapes.clear();
  obstacle_shapes.clear();
}

ObstacleParameterReader::~ObstacleParameterReader() {
  // do nothing
}

/**
* Obtain obstacle ellipsoid info of a robot from YAML file.
* @param[in] body a pointer to the body of target robot
* @param[in] arm  a pointer to the target arm
*/
void ObstacleParameterReader::readRobotYamlFile(BodyPtr body, ArmPtr arm) {
  clear_arms();
  arm_shapes = ArmShape::readYamlFile(body, arm);
}

/**
* Obtain obstacle ellipsoid info of environment objects from YAML file.
* @param[in] body body pointer of robot
*/
void ObstacleParameterReader::readEnvYamlFiles(BodyPtr body) {
	clear_obstacles();
	list<BodyItemPtr> envs = PlanBase::instance()->getBodyItemEnv(body);
	for (list<BodyItemPtr>::iterator it = envs.begin(); it != envs.end(); ++it) {
		readEnvYamlFile(*it);
	}
}

/**
* Obtain obstacle ellipsoid info of environment objects from YAML file.
*/
void ObstacleParameterReader::readEnvYamlFiles() {
  clear_obstacles();
  for (list<BodyItemPtr>::iterator it = PlanBase::instance()->bodyItemEnv.begin(); it != PlanBase::instance()->bodyItemEnv.end(); ++it) {
    readEnvYamlFile(*it);
  }
}

/**
* Obtain obstacle ellipsoid info of a environment object from YAML file.
* @param[in] item BodyItemPtr of target object
*/
void ObstacleParameterReader::readEnvYamlFile(BodyItemPtr item) {
  ObstacleShapeVec tmp_obs = ObstacleShape::readYamlFile(item);
  obstacle_shapes.insert(obstacle_shapes.end(), tmp_obs.begin(), tmp_obs.end());
}

/**
* Clear obstacle ellipsoid shapes of the robot.
*/
void ObstacleParameterReader::clear_arms() {
  arm_shapes.clear();
}

/**
* Clear obstacle ellipsoid shapes of environment objects.
*/
void ObstacleParameterReader::clear_obstacles() {
  obstacle_shapes.clear();
}

/**
* Get obstacle ellipsoid shapes of the robot.
* @return obstacle ellipsoids of the robot
*/
ArmShapeVec ObstacleParameterReader::getArmShapes() const {
  return arm_shapes;
}

/**
* Get obstacle ellipsoid shapes of environment objects.
* @return obstacle ellipsoids of environment objecrts
*/
ObstacleShapeVec  ObstacleParameterReader::getObstacleShapes() const {
  return obstacle_shapes;
}

/**
* Update ellipsoid matrix E, inverse matrix of E, etc. 
* This method must be invoked if @c p or @c R is changed.
*/
void EllipsoidShape::updateParameters() {
	E = cnoid::Vector3(1.0/(a()*a()), 1.0/(b()*b()), 1.0/(c()*c())).asDiagonal();
	E = R * E * R.transpose();
	invE = E.inverse();

	Eigen::SelfAdjointEigenSolver<cnoid::Matrix3> es(E);
	sqrtE = es.operatorSqrt();
	inv_sqrtE = sqrtE.inverse();
}

ObstacleShape::ObstacleShape(Link* _obj) {
  offset = Vector3::Zero();
  min_interval = 0;
  effective_dist = 0.1;
  xi = 0.1;
  obj = _obj;
}

ObstacleShape::~ObstacleShape() {
  // do nothing
}

/**
* Obtain obstacle ellipsoid info from YAML file.
* @param[in] item BodyItemPtr of the target object
* @return obstacle sahpes
*/
ObstacleShapeVec ObstacleShape::readYamlFile(cnoid::BodyItemPtr item) {
  ObstacleShapeVec ret;

  if (item->body()->info()->find("collisionShape")->NODE_TYPE != YAML_SEQUENCE) {
    return ret;
  }
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
  const YamlSequence& glist = *(*item->body()->info())["collisionShape"].toSequence();
#else
  const Listing& glist = *(*item->body()->info())["collisionShape"].toListing();
#endif

  for (int i = 0; i < glist.size(); i++) {
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
    const YamlMapping& gSettings = *glist[i].toMapping();
#else
    const Mapping& gSettings = *glist[i].toMapping();
#endif
    if (!gSettings.isValid() || gSettings.empty()) {
      continue;
    }

    ObstacleShape* obstacle = new ObstacleShape(item->body()->link(0));

    if (gSettings.find("center")->NODE_TYPE == YAML_SEQUENCE) {
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
      const YamlSequence& list = *gSettings["center"].toSequence();
#else
      const Listing& list = *gSettings["center"].toListing();
#endif
      if (list.size() >= 3) {
				obstacle->setCenter(Vector3(list[0].toDouble(), list[1].toDouble(), list[2].toDouble()));
      }
    }

    if (gSettings.find("rpy")->NODE_TYPE == YAML_SEQUENCE) {
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
      const YamlSequence& list = *gSettings["rpy"].toSequence();
#else
      const Listing& list = *gSettings["rpy"].toListing();
#endif
      if (list.size() >= 3) {
				obstacle->relR = rotFromRpy(Vector3(list[0].toDouble(), list[1].toDouble(), list[2].toDouble()));
      }
    }

    if (gSettings.find("length")->NODE_TYPE == YAML_SEQUENCE) {
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
      const YamlSequence& list = *gSettings["length"].toSequence();
#else
      const Listing& list = *gSettings["length"].toListing();
#endif
      if (list.size() >= 3) {
        obstacle->setRadius(Vector3(list[0].toDouble(), list[1].toDouble(), list[2].toDouble()));
      }
    }

    if (gSettings.find("security_distance")->NODE_TYPE == YAML_SCALAR) {
      obstacle->setMinInterval(gSettings["security_distance"].toDouble());
    }

    if (gSettings.find("effective_distance")->NODE_TYPE == YAML_SCALAR) {
      obstacle->setEffectiveDist(gSettings["effective_distance"].toDouble());
    }

    if (gSettings.find("xi")->NODE_TYPE == YAML_SCALAR) {
      obstacle->setEffectiveDist(gSettings["xi"].toDouble());
    }

    ret.push_back(obstacle);
  }

  return ret;
}

/**
* Get the center position in world coordinate.
* @return center poistion
*/
Vector3 ObstacleShape::getPos() const {
  Vector3 target_pos = obj->p() + obj->attitude() * offset;
  return target_pos;
}

/**
* Set the center position in the link local coordinate.
* @param[in] _pos center poistion(link local)
*/
void ObstacleShape::setCenter(const cnoid::Vector3& _offset) {
  offset = _offset;
}

/**
* Update the position,  the rotation matrix and paremeters.
*/
void ObstacleShape::updatePos() {
  p = getPos();
  R = obj->attitude() * relR;

  updateParameters();
}

ArmShape::ArmShape(ArmPtr _arm) {
  joint_num = 0;
  arm = _arm;
  offset = Vector3::Zero();
}

ArmShape::~ArmShape() {
  // do nothing
}

/**
* Obtain obstacle ellipsoid info of the robot arm from YAML file.
* @param[in] body a pointer to the target robot
* @param[in] arm_ptr a pointer to the target arm
* @return obstacle sahpes of arm
*/
ArmShapeVec ArmShape::readYamlFile(BodyPtr body, ArmPtr arm_ptr) {
  ArmShapeVec ret;

  if (body->info()->find("collisionShape")->NODE_TYPE != YAML_SEQUENCE) {
    return ret;
  }

#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
  const YamlSequence& glist = *(*(body->info()))["collisionShape"].toSequence();
#else
  const Listing& glist = *(*(body->info()))["collisionShape"].toListing();
#endif

  for (int i = 0; i < glist.size(); i++) {
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
    const YamlMapping& gSettings = *glist[i].toMapping();
#else
    const Mapping& gSettings = *glist[i].toMapping();
#endif
    if (!gSettings.isValid() || gSettings.empty()) {
      continue;
    }

    ArmShape* arm_shape = new ArmShape(arm_ptr);

    if (gSettings.find("center")->NODE_TYPE == YAML_SEQUENCE) {
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
      const YamlSequence& list = *gSettings["center"].toSequence();
#else
      const Listing& list = *gSettings["center"].toListing();
#endif
      if (list.size() >= 3) {
				arm_shape->setCenter(Vector3(list[0].toDouble(), list[1].toDouble(), list[2].toDouble()));
      }
    }

    if (gSettings.find("rpy")->NODE_TYPE == YAML_SEQUENCE) {
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
      const YamlSequence& list = *gSettings["rpy"].toSequence();
#else
      const Listing& list = *gSettings["rpy"].toListing();
#endif
      if (list.size() >= 3) {
				arm_shape->relR = rotFromRpy(Vector3(list[0].toDouble(), list[1].toDouble(), list[2].toDouble()));
      }
    }

    if (gSettings.find("length")->NODE_TYPE == YAML_SEQUENCE) {
#if defined(CNOID_10_11_12_13) || defined(CNOID_14)
      const YamlSequence& list = *gSettings["length"].toSequence();
#else
      const Listing& list = *gSettings["length"].toListing();
#endif
      if (list.size() >= 3) {
        arm_shape->setRadius(Vector3(list[0].toDouble(), list[1].toDouble(), list[2].toDouble()));
      }
    }

    if (gSettings.find("jointName")->NODE_TYPE == YAML_SCALAR) {
      Link* tmp_link = body->link(gSettings["jointName"].toString());

      // int joint_num = arm_ptr->arm_path->indexOf(tmp_link);
      int joint_num = -1;
      for (int i = 0; i < arm_ptr->arm_path->numJoints(); ++i) {
        if (arm_ptr->arm_path->joint(i) == tmp_link) {
          joint_num = i;
          break;
        }
      }

      if (joint_num != -1) {
				arm_shape->setJointNum(joint_num);
			} else {
				// If the shape is not associated with target arm in the yaml file, that shape is associated with base link. 
				arm_shape->setJointNum(0);
				arm_shape->setCenter(arm_ptr->arm_path->joint(0)->attitude().transpose() * (tmp_link->attitude() * arm_shape->getCenter() + tmp_link->p() - arm_ptr->arm_path->joint(0)->p()));
				arm_shape->setRelR(arm_ptr->arm_path->joint(0)->attitude().transpose() * tmp_link->attitude() * arm_shape->getRelR());
				}
    }
    ret.push_back(arm_shape);
  }

  return ret;
}

/**
* Get the center position in world coordinate.
* @return center poistion
*/
Vector3 ArmShape::getPos() const {
  Vector3 target_pos = arm->arm_path->joint(joint_num)->p() + arm->arm_path->joint(joint_num)->attitude() * offset;
  return target_pos;
}

/**
* Set the center position in the link local coordinate.
* @param[in] _pos center poistion(link local)
*/
void ArmShape::setCenter(const Vector3& _offset) {
  offset = _offset;
}

/**
* Update the position,  the rotation matrix and paremeters.
*/
void ArmShape::updatePos() {
  p = getPos();
  R = arm->arm_path->joint(joint_num)->attitude() * relR;

  updateParameters();
}

AbstractEllipsoidDistCalculator::AbstractEllipsoidDistCalculator() {
  // do nothing
}

AbstractEllipsoidDistCalculator::~AbstractEllipsoidDistCalculator() {
  // do nothing
}

ApproximateEllipsoidDistCalculator::ApproximateEllipsoidDistCalculator() {
  // do nothing
}

ApproximateEllipsoidDistCalculator::~ApproximateEllipsoidDistCalculator() {
  // do nothing
}

/**
* Obtain approximate distance between ellipsoids.
* @param[in] e1,e2 a pointer to target ellipoid
* @param[out] p1 closest point to @c e1 on @c e2
* @param[out] p2 closest point on @c e2 on @c e1
* @return distance between ellipsoids
*/
double ApproximateEllipsoidDistCalculator::calcDistance(const EllipsoidShape* e1, const EllipsoidShape* e2, cnoid::Vector3& p1, cnoid::Vector3& p2) const {
  Vector3 c1 = e1->getP();
  Vector3 c2 = e2->getP();

  // calculate closest point on e2 to the center of e1
  Matrix3 isE1 = e1->getInvSqrtE();
  Matrix3 barE2 = isE1 * e2->getE() * isE1;

  Eigen::SelfAdjointEigenSolver<Matrix3> esbar2(barE2);
  Matrix3 inv_sqrt_barE2 = esbar2.operatorInverseSqrt();
  Matrix3 tildeE2        = barE2.inverse();
  Vector3 bar_p2         = e1->getSqrtE() * (c2 - c1);
  Vector3 tilde_p2       = inv_sqrt_barE2 * bar_p2;

  MatrixXd m1(6, 6);
  m1 << tildeE2, -Matrix3::Identity(), -tilde_p2 * tilde_p2.transpose(), tildeE2;
  double lambda1 = m1.eigenvalues().real().minCoeff();

  p2 = c1 + lambda1 * isE1 * (lambda1 * Matrix3::Identity() - tildeE2).inverse() * bar_p2;

  // calculate closest point on e1 to p2
  Matrix3 iE1      = e1->getInvE();
  Vector3 bar_p1   = (c1 - p2);
  Vector3 tilde_p1 = isE1 * bar_p1;

  MatrixXd m2(6, 6);
  m2 << iE1, -Matrix3::Identity(), -tilde_p1 * tilde_p1.transpose(), iE1;
  double lambda2 = m2.eigenvalues().real().minCoeff();

  p1 = p2 + lambda2 * (lambda2 * Matrix3::Identity() - iE1).inverse() * (c1-p2);


  return norm2(p1-p2);
}

SteepestDescentEllipsoidDistCalculator::SteepestDescentEllipsoidDistCalculator() {
  // do nothing
}

SteepestDescentEllipsoidDistCalculator::~SteepestDescentEllipsoidDistCalculator() {
  // do nothing
}

/**
* Calculate approximate distance between ellipsoids by using steepest descent method.
* @param[in] e1,e2 a pointer to target ellipoid
* @param[out] p1 closest point to @c e1 on @c e2
* @param[out] p2 closest point to @c e2 on @c e1
* @return distance between ellipsoids
*/
double SteepestDescentEllipsoidDistCalculator::calcDistance(const EllipsoidShape* e1, const EllipsoidShape* e2, cnoid::Vector3& p1, cnoid::Vector3& p2) const {
  double e = 4 * 10e-6;
  VectorXd x(4);
  getInitSol(e1, e2, x(0), x(1));
  getInitSol(e2, e1, x(2), x(3));

  VectorXd delta(4);
  double alpha = 0.0001;
  double beta = 0.5;
  double step = 0.1;

  while (true) {
    calcDelta(e1, e2, x, delta);
    if (norm2(delta) < e)
      break;
    VectorXd d = -delta;
    for (int l = 0; l < 100; l++) {
      step = pow(beta, l);
      double diff = getDistance(e1, e2, x+step*d) - getDistance(e1, e2, x);
      double dd = alpha * step * delta.transpose() * d;
      if (diff <= dd) {
        break;
      }
    }
    x = x + step*d;
  }

  p1 = getSurfacePoint(e1, x(0), x(1));
  p2 = getSurfacePoint(e2, x(2), x(3));
  return norm2(p1 - p2);
}

void SteepestDescentEllipsoidDistCalculator::getInitSol(const EllipsoidShape* shp1, const EllipsoidShape* shp2, double& theta, double& phi) const {
  double a2 = shp1->a() * shp1->a();
  double b2 = shp1->b() * shp1->b();
  double c2 = shp1->c() * shp1->c();

  Vector3 r = shp1->getR().transpose() * (shp2->getP() - shp1->getP());

  double t = (shp1->a() * shp1->b() * shp1->c())/sqrt(b2*c2*r(0)*r(0)+ a2*c2*r(1)*r(1) + a2*b2*r(2)*r(2));
  if (t < 0) t= -t;

  Vector3 p = t *  r;
  theta = acos(p(2)/shp1->c());
  phi = atan((p(1)*shp1->a())/(p(0)*shp1->b()));
  if (r(0) * (shp1->a() * sin(theta) * cos(phi)) < 0) phi += M_PI;
}

void SteepestDescentEllipsoidDistCalculator::calcDelta(const EllipsoidShape* shp1, const EllipsoidShape* shp2, const cnoid::VectorXd& x, cnoid::VectorXd& delta) const {
  Matrix3 relR = shp1->getR().transpose() * shp2->getR();
  Vector3 relp = shp1->getR().transpose() * (shp2->getP() - shp1->getP());
  double t1 = x(0);
  double t2 = x(2);
  double p1 = x(1);
  double p2 = x(3);

  double a2 = shp1->a() * shp1->a();
  double b2 = shp1->b() * shp1->b();
  double c2 = shp1->c() * shp1->c();

  Vector3 e1 = Vector3(shp1->a() * sin(t1) * cos(p1), shp1->b() * sin(t1) * sin(p1), shp1->c() * cos(t1));
  Vector3 e2 = Vector3(shp2->a() * sin(t2) * cos(p2), shp2->b() * sin(t2) * sin(p2), shp2->c() * cos(t2));

  double d_theta2 = (a2*cos(p1)*cos(p1) + b2*sin(p1)*sin(p1) - c2) * sin(2*t1);
  double d_phi2   = (-a2*sin(t1)*sin(t1) + b2*sin(t1)*sin(t1)) * sin(2*p1);
  Vector3 d_theta = Vector3(shp1->a() *cos(t1) * cos(p1), shp1->b()*cos(t1)*sin(p1), -shp1->c()*sin(t1));
  Vector3 d_phi   = Vector3(-shp1->a() *sin(t1) * sin(p1), shp1->b()*sin(t1)*cos(p1), 0);

  Vector3 tmp = relR * e2 + relp;
  delta(0) = d_theta2 - (2 * tmp.transpose() * d_theta);
  delta(1) = d_phi2 - (2 * tmp.transpose() * d_phi);

  a2 = shp2->a() * shp2->a();
  b2 = shp2->b() * shp2->b();
  c2 = shp2->c() * shp2->c();

  d_theta2 = (a2*cos(p2)*cos(p2) + b2*sin(p2)*sin(p2) - c2) * sin(2*t2);
  d_phi2   = (-a2*sin(t2)*sin(t2) + b2*sin(t2)*sin(t2)) * sin(2*p2);
  d_theta = Vector3(shp2->a() *cos(t2) * cos(p2), shp2->b()*cos(t2)*sin(p2), -shp2->c()*sin(t2));
  d_phi   = Vector3(-shp2->a() *sin(t2) * sin(p2), shp2->b()*sin(t2)*cos(p2), 0);

  tmp = relp - e1;
  delta(2) = d_theta2 + 2 * tmp.transpose() * relR * d_theta;
  delta(3) = d_phi2 + 2 * tmp.transpose() * relR * d_phi;
}

double SteepestDescentEllipsoidDistCalculator::getDistance(const EllipsoidShape* shp1, const EllipsoidShape* shp2, const cnoid::VectorXd& x) const {
  return norm2(getSurfacePoint(shp1, x(0), x(1)) - getSurfacePoint(shp2, x(2), x(3)));
}

Vector3 SteepestDescentEllipsoidDistCalculator::getSurfacePoint(const EllipsoidShape* shp, double theta, double phi) const {
  double x = shp->a() * sin(theta) * cos(phi);
  double y = shp->b() * sin(theta) * sin(phi);
  double z = shp->c() * cos(theta);

  Vector3 surface_p = shp->getR() * Vector3(x, y, z) + shp->getP();
  return surface_p;
}
