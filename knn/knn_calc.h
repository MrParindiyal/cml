#ifndef KNN_CALC_H
#define KNN_CALC_H

#include "handle_csv.h"

float get_euclidean_distance(float, float, float, float);
df* calculate_dist(df*, float, float);
void swap_struct(df*, df*);
df* sort_df(df*);
void quick_sort(df*, int, int);
int get_k_val();
void print_predicted_class(df*, int);

#endif