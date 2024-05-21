#include <stdio.h>
#include <string.h>

int main() 
{
    char str_arr[1002];

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int longest_start_pos = -1;
    int longest_end_pos = -1;
    int start_pos = -1;
    int end_pos = -1;
    int len = strlen(str_arr);
    for ( int i = 0; i < len; i++) 
    {
        if (str_arr[i] == ' ' || str_arr[i] == '.' || str_arr[i] == ',' /*|| str_arr[i] >= '0' && str_arr[i] <= '9'*/) 
        {
            if (start_pos >= 0) 
            {
                if (longest_start_pos == -1 || end_pos - start_pos > longest_end_pos - longest_start_pos) 
                {
                    longest_start_pos = start_pos;
                    longest_end_pos = end_pos;
                }
            }
            start_pos = -1;
            end_pos = -1; 
        } else {
            if (start_pos == -1)
                start_pos = i;
            end_pos = i;
        }
    }

    if (start_pos >= 0 && (end_pos - start_pos > longest_end_pos - longest_start_pos || longest_start_pos == -1)) 
    {
        longest_start_pos = start_pos;
        longest_end_pos = end_pos;
    }


    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    if (longest_start_pos >= 0) 
    {
        for ( int i = longest_start_pos; i <= longest_end_pos; i++) 
        {
            fprintf(f_out, "%c", str_arr[i]);        
        }
    }
    fclose(f_out);

    return 0;
}
