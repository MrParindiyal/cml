#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO
#define MAX_PATH_LENGTH 260
#define MAX_ROWS 5000

typedef char* string;

typedef struct{
    string row_name;
    float x;
    float y;
    int class;
    float dis;
} df;

string get_path();
df* read_csv();
void print_df(df*, int);
void print_df_full(df*);
float* get_point();
float get_euclidean_distance(float, float, float, float);
df* calculate_dist(df* , float, float);

int main(){
    df* data = read_csv();
    printf("\n+++++++++++++++++\n");\
    // print_df_full(data);
    print_df(data,10);

    float* user_input = get_point();
    printf("\nYour input was : x = %f, y = %f\n", user_input[0], user_input[1]);
    data = calculate_dist(data, user_input[0], user_input[1]);
    print_df_full(data);
    free(data);
    free(user_input);
    return 0;
}

string get_path(){
    string path = malloc(sizeof(char) * 5000);
    if (path == NULL) {  // Check if malloc failed
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter path: ");
    if (fgets(path, MAX_PATH_LENGTH, stdin)){
        // Remove newline character if present
        size_t len = strlen(path);
        if (len > 0 && path[len - 1] == '\n') {
            path[len - 1] = '\0';
        }
    }
    else {
        printf("Error reading input\n");
        free(path);  
        return NULL;
    }

    printf("You entered: %s\n", path);
    return path;
}

df* read_csv(void)
{
    char separators[] = ",\n";
    string token;
    // df* dataframe = NULL;
    FILE*fiter = fopen("test.csv", "r");

    if (fiter != NULL){
        printf("File open success\n\n");
        df* dataframe = (df*)malloc(MAX_ROWS * sizeof(df));
        char buffer[256];
        int q = 0;
        while (fgets(buffer, sizeof(buffer), fiter) != NULL) {
            token = strtok(buffer, separators);
            while( token != NULL )
            {// While there are tokens in "buffer"                 
                dataframe[q].row_name = malloc(strlen(token) + 1);
                strcpy(dataframe[q].row_name, token);

                token = strtok( NULL, separators);
                dataframe[q].x = strtof(token, NULL);
                // printf( " %s\n", token );
                
                token = strtok( NULL, separators);
                dataframe[q].y = strtof(token, NULL);
                // printf( " %s\n", token );
                
                token = strtok( NULL, separators);
                dataframe[q].class = strtol(token, NULL, 10);
                // printf( " %s\n", token );
                
                dataframe[q].dis = 0;

                token = strtok( NULL, separators);

            }
            q++;
        }
        fclose(fiter);
        return dataframe;    
    }

    else{
        printf("Error opening the file");
        return NULL;
    }
    return NULL;
}

void print_df(df* dataframe, int rows){
    for (int i = 0; i < rows; i++){
        printf("%s ", dataframe[i].row_name);
        printf("%f ", dataframe[i].x);
        printf("%f ", dataframe[i].y);
        printf("%i ", dataframe[i].class);
        printf("%0.2f ", dataframe[i].dis);
        printf("\n");
    }
}

void print_df_full(df* dataframe){
    int i = 0;
    while(i < MAX_ROWS && dataframe[i].row_name != NULL){
        printf("%s ", dataframe[i].row_name);
        printf("%f ", dataframe[i].x);
        printf("%f ", dataframe[i].y);
        printf("%i ", dataframe[i].class);
        printf("%0.2f ", dataframe[i].dis);
        printf("\n");
        i++;
    }
}

float* get_point(){
    float* out = malloc(2 * sizeof(float));
    printf("\nEnter the x val of your data:\t");
    if(scanf("%f", &out[0]) != 1){
        printf("\nInvalid input, retry...\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter the y val of your data:\t");
    if(scanf("%f", &out[1]) != 1){
        printf("\nInvalid input, retry...\n");
        exit(EXIT_FAILURE);
    }
    return out;
}

float get_euclidean_distance(float x1, float y1, float x, float y){
    // same as float dist = sqrt(pow(x1-x, 2) + pow(y1-y, 2));
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