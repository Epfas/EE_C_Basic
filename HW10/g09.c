#include <stdio.h>
#include <string.h>

int main() 
{
    char str_arr[1000];
    int ex_arr[224] = {0};
    ex_arr[0] = 1;

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    int len = strlen(str_arr);
    if (len) 
    {
        for ( int i = 0; i < len; i++) 
        {
            if (!ex_arr[str_arr[i]-' ']) 
            {
                fprintf(f_out, "%c", str_arr[i]);        
                ex_arr[str_arr[i]-' ']++;
            }    
        }
    }
    fclose(f_out);

    return 0;
}
