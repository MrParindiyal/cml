#include "knn_calc.h"
#include "handle_csv.h"
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 5000

float get_euclidean_distance(float x1, float y1, float x, float y){
    // same as float dist = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
    float dist = sqrt(((x1 - x) * (x1 - x)) + ((y1 - y) * (y1 - y)));
    return dist;
}

df* calculate_dist(df* dataframe, float x, float y){
    int i = 0;
    while( i < MAX_ROWS && dataframe[i].row_name != NULL){
        dataframe[i].dis = get_euclidean_distance(dataframe[i].x, dataframe[i].y, x, y);
        i++;
    }
    return dataframe;
}

void swap_struct(df* a, df* b){
    df temp = *a;
    *a = *b;
    *b = temp;
    return;
}

df* sort_df(df* dataframe){
    int len = get_df_len(dataframe);
    quick_sort(dataframe, 0, len - 1);
    return dataframe;
}

void quick_sort(df* dataframe, int lb, int ub){
    if (lb < ub)
    {
        df pivot = dataframe[ub];
        int i = lb - 1;
        for (int j = lb; j <= ub; j++)
        {
            if (dataframe[j].dis < pivot.dis)
            {
                i++;
                // if i!=j then swap
                (i != j) ? swap_struct(&dataframe[j], &dataframe[i]) : 0;
            }
        }
        // at last, swap pivot to its location
        swap_struct(&dataframe[ub], &dataframe[++i]);

        // then recursive calls to left & right subarray
        quick_sort(dataframe, lb, i - 1);
        quick_sort(dataframe, i + 1, ub);
    }
}
