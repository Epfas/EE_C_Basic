
#include <stdio.h>
#include <string.h>

void extract_word(int from_pos, int to_pos, char str[], int * word_from, int * word_to) 
{
    *word_from = -1;
    *word_to = -1;

    for (int i = from_pos; i <= to_pos; i++) 
    {
        if (str[i] == ' ') 
        {
            if (*word_from >= 0)
                return;
        } else {
            if (*word_from == -1)
                *word_from = i;
            *word_to = i;
        }
    }
}

int main() 
{
    char str_arr[100];

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int len = strlen(str_arr);
    
    int ln_pos_start = -1;
    int ln_pos_end = -1;
    extract_word(0, len, str_arr, &ln_pos_start, &ln_pos_end);

    int fn_pos_start = -1;
    int fn_pos_end = -1;
    extract_word(ln_pos_end +2, len, str_arr, &fn_pos_start, &fn_pos_end);

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    fprintf(f_out, "Hello, ");
    for (int i = fn_pos_start; i <= fn_pos_end; i++) 
    {
        fprintf(f_out, "%c", str_arr[i]);
    }
    fprintf(f_out, " ");
    for (int i = ln_pos_start; i <= ln_pos_end; i++) 
    {
        fprintf(f_out, "%c", str_arr[i]);
    }
    fprintf(f_out, "!");
    fclose(f_out);

    return 0;
}
