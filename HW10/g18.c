#include <stdio.h>
#include <string.h>

int del_spaces(int source_len, char source_str[], char result_str[])
{
    int res_len = 0;
    int before_space = 1;
    int first_space = 1;
    for (int i = 0; i < source_len; i++) {
        int to_transfer = 1;
        if (source_str[i] == ' ') 
        {
            if (before_space || !first_space) 
                to_transfer = 0;
            first_space = 0;
        } else {
            before_space = 0;
            first_space = 1;
        }       
        if (to_transfer) {
            result_str[res_len] = source_str[i];
            res_len++;
        }
    }
    
    return res_len;
}

int main() 
{
    char str_arr[1002] = "";
    char res_arr[1002] = "";
    
    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int len = strlen(str_arr);
    int res_len = del_spaces(len, str_arr, res_arr);
    
    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    for (int i = 0; i < res_len; i++) 
    {
        fprintf(f_out, "%c", res_arr[i]);
    }

    fclose(f_out);

    return 0;
}
