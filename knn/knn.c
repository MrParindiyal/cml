#include "knn_calc.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 260
#define MAX_ROWS 5000

int main(){
    df* data = read_csv();
    printf("\n+++++++++++++++++\n");
    print_df_full(data);
    // print_df(data,10);

    float* user_input = get_point();
    printf("\nYour input was : x = %f, y = %f\n", user_input[0], user_input[1]);
    data = calculate_dist(data, user_input[0], user_input[1]);
    data = sort_df(data);
    int k = get_k_val();
    print_predicted_class(data, k);
    // print_df_full(data);
    free(data);
    free(user_input);
    return 0;
}