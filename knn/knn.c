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
} df;

string get_path();
df* read_csv();
void print_df(df* dataframe, int r);
float* get_point();

int main(){
    df* data = read_csv();
    printf("\n+++++++++++++++++\n");\
    print_df(data, 15);

    float* user_input = get_point();
    printf("\nYour input was : x = %f, y = %f\n", user_input[0], user_input[1]);
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
        printf("\n");
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