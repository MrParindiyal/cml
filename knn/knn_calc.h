#ifndef KNN_CALC_H
#define KNN_CALC_H

// #ifndef MAX_PATH_LEN
// #define MAX_PATH_LEN 260 // Default value if not defined elsewhere
// #endif

// #ifndef MAX_ROWS
// #define MAX_ROWS 5000 // Default value if not defined elsewhere
// #endif

#include "handle_csv.h"

float get_euclidean_distance(float, float, float, float);
df* calculate_dist(df* , float, float);
void swap_struct(df*, df*);
df* sort_df(df*);
void quick_sort(df*, int, int);


#endif