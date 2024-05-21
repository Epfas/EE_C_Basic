#include <stdio.h>
#include <string.h>

int main() 
{
    char str_arr[1002] = "";
    
    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int len = strlen(str_arr);
    int pos1 = -1;
    for (int i = 0; i < len; i++) 
    {
        if (str_arr[i] != ' ') 
        {
            if (pos1 == -1) {
                pos1 = i;
            } else {
                char c = str_arr[i];
                str_arr[i] = str_arr[pos1];
                str_arr[pos1] = c;
                pos1 = -1;
            }           
        }         
    }
    
    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    for (int i = 0; i < len; i++) {
        fprintf(f_out, "%c", str_arr[i]);
    }

    fclose(f_out);

    return 0;
}
