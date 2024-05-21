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

    int dot_pos = -1;
    int len = strlen(str_arr);
    for ( int i = len-1; i >= 0; i--) 
    {
        if (str_arr[i] == '.') 
        {
            dot_pos = i; 
            break;
        }
        if (str_arr[i] == '/') 
            break;
    }
    if (dot_pos == -1)
      dot_pos = len;

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    for (int i = 0; i < dot_pos; i++) 
    {
        fprintf(f_out, "%c", str_arr[i]);
    }
    fprintf(f_out, ".html");
    fclose(f_out);

    return 0;
}
