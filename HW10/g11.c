#include <stdio.h>
#include <string.h>

int isCorrectWord(int from_pos, int to_pos, char str[]) 
{
    if (from_pos < 0 || to_pos < 0 || from_pos > to_pos)
        return 0;
    return (str[to_pos] == 'a' || str[to_pos] == 'A');
}

int main() 
{
    char str_arr[1002];

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int word_count = 0;
    int start_pos = -1;
    int end_pos = -1;
    int len = strlen(str_arr);
    for ( int i = 0; i < len; i++) 
    {
        if (str_arr[i] == ' ' || str_arr[i] == '.' || str_arr[i] == ',' /*|| str_arr[i] >= '0' && str_arr[i] <= '9'*/) 
        {
            if (start_pos >= 0) 
            {
                word_count += isCorrectWord(start_pos, end_pos, str_arr);
            }
            start_pos = -1;
            end_pos = -1; 
        } else {
            if (start_pos == -1)
                start_pos = i;
            end_pos = i;
        }
    }
    if (start_pos >= 0) 
        word_count += isCorrectWord(start_pos, end_pos, str_arr);

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;
    fprintf(f_out, "%d", word_count);        
    fclose(f_out);

    return 0;
}
