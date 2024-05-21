#include <stdio.h>
#include <string.h>


int main() 
{
    char str_arr[1002] = "";
    int letters_size = 26;
    int letters_cnt[letters_size];
    
    for (int i = 0; i < letters_size; i++) 
    {
        letters_cnt[i] = 0;
    }
    
    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int len = strlen(str_arr);
    for (int i = 0; i < len; i++) 
    {
        letters_cnt[str_arr[i] - 'a']++;
    }
    
    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    for (int i = 0; i < letters_size; i++) 
        for (int j = 0; j < letters_cnt[i] >> 1; j++) 
            fprintf(f_out, "%c", i+'a');
    
    for (int i = 0; i < letters_size; i++) 
        if (letters_cnt[i] % 2) {
            fprintf(f_out, "%c", i+'a');
            break;
        }
    
    for (int i = letters_size-1; i >= 0 ; i--) 
        for (int j = 0; j < letters_cnt[i] >> 1; j++) 
            fprintf(f_out, "%c", i+'a');

    fclose(f_out);

    return 0;
}
