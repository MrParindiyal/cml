#ifndef HANDLE_CSV_H
#define HANDLE_CSV_H

typedef char* string;
typedef struct{
    string row_name;
    float x;
    float y;
    int label;
    float dis;
} df;

string get_path();
df* read_csv();
int get_df_len(df*);
void print_df(df*, int);
void print_df_full(df*);
float* get_point();

#endif