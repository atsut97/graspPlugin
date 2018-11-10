double quadrics(object_data *o, int cn);
double normal_quadrics(object_data *o, int cn);
//double quadrics_error_from_triangle_q(triangle_data **tq, int cn,int size,int maxsize);
double quadrics_error_from_triangle_q(triangle_data **tq, int size);
double quadrics_error_from_triangle_list(triangle_data *t,int cn,int maxsize);
//double area_quadrics_error_from_triangle_q(triangle_data **tq, int cn,int size,int maxsize);
//double area_quadrics_error_from_triangle_q(object_data *o, int cn);
double area_quadrics_error_from_triangle_q(object_data *o, cluster_data *c);
double area_normalization_quadrics(object_data *o, int cn);
double area_normal_quadrics(object_data *o, int cn);
//double area_normal_and_position_covariance(object_data *o, int cn);
double area_normal_and_position_covariance(object_data *o, cluster_data *c);
double area_normal_quadrics_error_from_triangle_q(object_data *o, cluster_data *c);
