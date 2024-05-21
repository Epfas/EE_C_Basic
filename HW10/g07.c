#include <stdio.h>
#include <string.h>

int main() 
{
    char str_arr[10000];

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int cnt_low = 0;
    int cnt_up = 0;
    int len = strlen(str_arr);
    for ( int i = 0; i < len; i++) 
    {
        if (str_arr[i] >= 'A' && str_arr[i] <= 'Z') {
            cnt_up++;
        }
        if (str_arr[i] >= 'a' && str_arr[i] <= 'z') {
            cnt_low++;
        }
    }

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;
    fprintf(f_out, "%d", cnt_low);        
    fprintf(f_out, " %d", cnt_up);        
    fclose(f_out);

    return 0;
}
