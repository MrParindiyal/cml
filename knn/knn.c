#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO
#define MAX_PATH_LENGTH 260
typedef char* string;
typedef struct{
    string row_name;
    float x;
    float y;
    int class;
} df;


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

// TODO
df* read_csv(void)
{
    char separators[] = ",\n";
    string token;
    // df* dataframe = NULL;
    FILE*fiter = fopen("test.csv", "r");

    if (fiter != NULL){
        printf("File open success\n\n");
        df* dataframe = (df*)malloc(5000 * sizeof(df));
         char buffer[256];
        int q = 0;
        while (fgets(buffer, sizeof(buffer), fiter) != NULL) {
            token = strtok(buffer, separators);
            while( token != NULL )
            {
                // While there are tokens in "buffer"
                dataframe[q].row_name = token;
                printf( " %s\n", token );
                token = strtok( NULL, separators);
                
                dataframe[q].x = strtof(token, NULL);
                printf( " %s\n", token );
                token = strtok( NULL, separators);
                
                dataframe[q].y = strtof(token, NULL);
                printf( " %s\n", token );
                token = strtok( NULL, separators);
                
                dataframe[q].class = strtol(token, NULL, 10);
                printf( " %s\n", token );
                token = strtok( NULL, separators);
                
            }
            q++;
        }
        return dataframe;    
    }


    else{
        printf("Error opening the file");
        return NULL;
    }

    fclose(fiter);
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

int main(){
    // string path = get_path();
    // if (path != NULL){
    //     free(path);
    // }
    df* data = read_csv();

    printf("\n+++++++++++++++++\n");\
    printf("%s ", data[0].row_name);
    // print_df(data, 6);
    free(data);
    return 0;
}

