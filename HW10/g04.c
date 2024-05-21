#include <stdio.h>
#include <string.h>

int main() 
{
    char str_arr[201];

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int letter_counter[26][2] = {0};
    int word_no = 0;
    int len = strlen(str_arr);
    if (len) 
    {
        for ( int i = 0; i < len; i++) 
        {
            if (str_arr[i] == ' ') {
                word_no++;
                if (word_no > 1)      
                    break; 
            } 
            else if (str_arr[i] >= 'a' && str_arr[i] <= 'z') 
            {
                letter_counter[str_arr[i]-'a'][word_no]++;
            }
        }
    }

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;
     
    for(int i = 0; i < 26; i++) 
    {
        if (letter_counter[i][0] == 1 && letter_counter[i][1] == 1) 
                fprintf(f_out, " %c",  i + 'a');        
    }
    fclose(f_out);

    return 0;
}
