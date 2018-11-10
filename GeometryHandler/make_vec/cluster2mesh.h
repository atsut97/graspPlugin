void search_vertices_of_base_model(object_data *o);
void make_cluster_boundaries(object_data *o);
void make_polygons(object_data *o);
void change_polygon_to_triangles_by_shortest(object_data *o);
void reinitialize_clusters(object_data *o);
int change_hierarchical_cluster_to_mesh(object_data *o);
void reinitialize_vertex_and_clusters(object_data *o);
void after_processing_of_vertex_hierachies(object_data *o);
void make_polygon_of_cluster(cluster_data *c,int dir,cluster_data *bcn);
void initial_edge_data(object_data *o);
void make_polygon_of_cluster2(cluster_data *c, cluster_data *bc, cluster_data *c2);
void write_vec_data(char *file,object_data *o);
void write_trivec_data(char *file,object_data *o);