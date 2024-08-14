#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// TODO
#define MAX_PATH_LENGTH 260
typedef char* string;


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



int main(){
    string path = get_path();
    if (path != NULL){
        free(path);
    }
    return 0;
}