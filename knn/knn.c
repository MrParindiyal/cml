#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 260;
typedef char* string;


string get_path(){
    char path[5000];
    printf("Enter path: ");
    if (fgets(path, sizeof(path), stdin)){
        // Remove newline character if present
        size_t len = strlen(path);
        if (len > 0 && path[len - 1] == '\n') {
            path[len - 1] = '\0';
        }
    }

    printf("You entered: %s\n", path);
    return *path;
}

int main(){

    get_path();
    return 0;
}