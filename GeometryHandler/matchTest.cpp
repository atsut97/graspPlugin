#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
#include<iostream>

#include "GeometryHandle.h"

using namespace std;
using namespace cnoid;
using namespace grasp;


int main(int argc, char* argv[]){
//	if (argc != 3 ){
//		cout << "program inputfile outputfile\n" << endl;
//		exit(0);
//	}
	
	MatrixXd sumQuadDistribution1(10,10),sumQuadDistribution2(10,10);
	sumQuadDistribution1 << 
	21.6588,18.0367,3.12066,6.35713,-7.33003e-06,-1.67299e-05,174.756,316.517,-0.000406378,8200.27
	,18.0367,65.2864,13.3648,4.07915,-6.12477e-06,-2.68638e-06,68.2938,929.542,-0.000105003,14237.9
	,3.12066,13.3648,9.09207,0.0458152,-1.80145e-06,2.56049e-07,1.28824,228.442,-3.72765e-05,5752.24
	,6.35713,4.07915,0.0458152,18.0367,-2.68638e-06,-7.33003e-06,316.517,68.2938,-8.49512e-05,1259.02
	,-7.33003e-06,-6.12477e-06,-1.80145e-06,-2.68638e-06,13.3648,0.0458152,-8.49512e-05,-0.000105003,228.442,-0.00269717
	,-1.67299e-05,-2.68638e-06,2.56049e-07,-7.33003e-06,0.0458152,3.12066,-0.000406378,-8.49512e-05,1.28824,-0.00752771
	,174.756,68.2938,1.28824,316.517,-8.49512e-05,-0.000406378,8200.27,1259.02,-0.00752771,35450.7
	,316.517,929.542,228.442,68.2938,-0.000105003,-8.49512e-05,1259.02,14237.9,-0.00269717,234464
	,-0.000406378,-0.000105003,-3.72765e-05,-8.49512e-05,228.442,1.28824,-0.00752771,-0.00269717,5752.24,-0.179469
	,8200.27,14237.9,5752.24,1259.02,-0.00269717,-0.00752771,35450.7,234464,-0.179469,6.63609e+06;
	
	sumQuadDistribution2 << 
	1.89837,0.403094,1.94504,0.0199382,0.000460172,0.211817,-6.89854,-0.952309,9.02022,2074.77
	,0.403094,1.12297,1.72246,0.0133246,-0.00682569,-0.0120672,-6.61313,-3.09549,3.83163,1708.11
	,1.94504,1.72246,9.32545,0.0147735,0.0438181,0.390054,-15.0175,-2.86024,-71.7264,4751.28
	,0.0199382,0.0133246,0.0147735,0.403094,-0.0120672,0.000460172,-0.952309,-6.61313,0.0208841,14.5135
	,0.000460172,-0.00682569,0.0438181,-0.0120672,1.72246,0.0147735,0.0208841,3.83163,-2.86024,14.0608
	,0.211817,-0.0120672,0.390054,0.000460172,0.0147735,1.94504,9.02022,0.0208841,-15.0175,206.051
	,-6.89854,-6.61313,-15.0175,-0.952309,0.0208841,9.02022,2074.77,14.5135,206.051,-9555.22
	,-0.952309,-3.09549,-2.86024,-6.61313,3.83163,0.0208841,14.5135,1708.11,14.0608,-2504.82
	,9.02022,3.83163,-71.7264,0.0208841,-2.86024,-15.0175,206.051,14.0608,4751.28,-19335.4
	,2074.77,1708.11,4751.28,14.5135,14.0608,206.051,-9555.22,-2504.82,-19335.4,4.38457e+06;	
	//cout << distribute2 << endl;
	
	MatrixXd M(9,9);
	MatrixXd N(9,9);
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			M(i,j)=sumQuadDistribution1(i,j) - sumQuadDistribution1(i,9)*sumQuadDistribution1(9,j)/sumQuadDistribution1(9,9);
			N(i,j)=sumQuadDistribution2(i,j) - sumQuadDistribution2(i,9)*sumQuadDistribution2(9,j)/sumQuadDistribution2(9,9);
//			N(i,j)=sumQuadError(i,j);
		}
	}
	
	MatrixXd M2(3,3);
	MatrixXd N2(3,3);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			M2(i,j)=sumQuadDistribution1(i+6,j+6) - sumQuadDistribution1(i+6,9)*sumQuadDistribution1(9,j+6)/sumQuadDistribution1(9,9);
			N2(i,j)=sumQuadDistribution2(i+6,j+6) - sumQuadDistribution2(i+6,9)*sumQuadDistribution2(9,j+6)/sumQuadDistribution2(9,9);
//			N(i,j)=sumQuadError(i,j);
		}
	}	
	cout <<"m"<< M2 <<endl <<  N2 << endl;
	
	
	Eigen::JacobiSVD<cnoid::MatrixXd> svd(M*N, Eigen::ComputeThinU | Eigen::ComputeThinV);
		
	cnoid::VectorXd s = svd.singularValues(); 

	MatrixXd _a_pseu = svd.matrixV().transpose() * svd.matrixU()  ;
	
	cout << s.transpose() << endl;
	
	cout << _a_pseu << endl;
	
}

/*
0.558927,,,,,,,,,,
,-0.455976,-0.436574,-0.773849,-0.0352054,-7.29787e-07,1.63017e-06,0.00548868,0.0371143,3.76223e-08,0.000836964
,,,,,,,,,,
,21.6588,18.0367,3.12066,6.35713,-7.33003e-06,-1.67299e-05,174.756,316.517,-0.000406378,8200.27
,18.0367,65.2864,13.3648,4.07915,-6.12477e-06,-2.68638e-06,68.2938,929.542,-0.000105003,14237.9
,3.12066,13.3648,9.09207,0.0458152,-1.80145e-06,2.56049e-07,1.28824,228.442,-3.72765e-05,5752.24
,6.35713,4.07915,0.0458152,18.0367,-2.68638e-06,-7.33003e-06,316.517,68.2938,-8.49512e-05,1259.02
,-7.33003e-06,-6.12477e-06,-1.80145e-06,-2.68638e-06,13.3648,0.0458152,-8.49512e-05,-0.000105003,228.442,-0.00269717
,-1.67299e-05,-2.68638e-06,2.56049e-07,-7.33003e-06,0.0458152,3.12066,-0.000406378,-8.49512e-05,1.28824,-0.00752771
,174.756,68.2938,1.28824,316.517,-8.49512e-05,-0.000406378,8200.27,1259.02,-0.00752771,35450.7
,316.517,929.542,228.442,68.2938,-0.000105003,-8.49512e-05,1259.02,14237.9,-0.00269717,234464
,-0.000406378,-0.000105003,-3.72765e-05,-8.49512e-05,228.442,1.28824,-0.00752771,-0.00269717,5752.24,-0.179469
,8200.27,14237.9,5752.24,1259.02,-0.00269717,-0.00752771,35450.7,234464,-0.179469,6.63609e+06
,,,,,,,,,,
,3.28011,0,0,0.251805,0,-1.50554e-06,7.09013,0,0,
,0,5.69514,0,0.251805,-5.39434e-07,0,0,46.8928,0,
,0,0,2.3009,0,-5.39434e-07,-1.50554e-06,0,0,-3.58939e-05,
,0.251805,0.251805,0,2.24381,-7.52771e-07,-2.69717e-07,23.4464,3.54507,0,
,0,-5.39434e-07,-5.39434e-07,-7.52771e-07,1.99901,0.125902,0,-1.79469e-05,23.4464,
,-1.50554e-06,0,-1.50554e-06,-2.69717e-07,0.125902,1.39525,-1.79469e-05,0,3.54507,
,7.09013,0,0,23.4464,0,-1.79469e-05,663.609,0,0,
,0,46.8928,0,3.54507,-1.79469e-05,0,0,663.609,0,
,0,0,-3.58939e-05,0,23.4464,3.54507,0,0,663.609,
,,,,,,,,,,
,0.174547,,,,,,,,,
,0.555172,0.830488,0.0209564,-0.0139175,-0.00109139,-0.0376247,0.00236373,0.000903585,-0.00422527,-0.000620099
,,,,,,,,,,
,1.89837,0.403094,1.94504,0.0199382,0.000460172,0.211817,-6.89854,-0.952309,9.02022,2074.77
,0.403094,1.12297,1.72246,0.0133246,-0.00682569,-0.0120672,-6.61313,-3.09549,3.83163,1708.11
,1.94504,1.72246,9.32545,0.0147735,0.0438181,0.390054,-15.0175,-2.86024,-71.7264,4751.28
,0.0199382,0.0133246,0.0147735,0.403094,-0.0120672,0.000460172,-0.952309,-6.61313,0.0208841,14.5135
,0.000460172,-0.00682569,0.0438181,-0.0120672,1.72246,0.0147735,0.0208841,3.83163,-2.86024,14.0608
,0.211817,-0.0120672,0.390054,0.000460172,0.0147735,1.94504,9.02022,0.0208841,-15.0175,206.051
,-6.89854,-6.61313,-15.0175,-0.952309,0.0208841,9.02022,2074.77,14.5135,206.051,-9555.22
,-0.952309,-3.09549,-2.86024,-6.61313,3.83163,0.0208841,14.5135,1708.11,14.0608,-2504.82
,9.02022,3.83163,-71.7264,0.0208841,-2.86024,-15.0175,206.051,14.0608,4751.28,-19335.4
,2074.77,1708.11,4751.28,14.5135,14.0608,206.051,-9555.22,-2504.82,-19335.4,4.38457e+06
,,,,,,,,,,
,0.829909,0,0,0.0029027,0,0.0412103,-1.91104,0,0,
,0,0.683243,0,0.0029027,0.00281215,0,0,-0.500963,0,
,0,0,1.90051,0,0.00281215,0.0412103,0,0,-3.86707,
,0.0029027,0.0029027,0,0.378288,0.0206051,0.00140608,-0.250482,-0.955522,0,
,0,0.00281215,0.00281215,0.0206051,0.645938,0.00145135,0,-1.93354,-0.250482,
,0.0412103,0,0.0412103,0.00140608,0.00145135,0.682605,-1.93354,0,-0.955522,
,-1.91104,0,0,-0.250482,0,-1.93354,438.457,0,0,
,0,-0.500963,0,-0.955522,-1.93354,0,0,438.457,0,
,0,0,-3.86707,0,-0.250482,-0.955522,0,0,438.457,
*/