
#include <stdio.h>
#include <string.h>

int found_text(int from_pos, int to_pos, char text_str[], int word_len, char word_str[]) 
{
    if (word_len) 
    {
        int curr_pos = from_pos;
        while (curr_pos <= to_pos) 
        {
            int i;
            for (i = 0; i < word_len; i++) 
            {
                if (text_str[curr_pos+i] != word_str[i])
                    break;
            }
            if (i == word_len) {
                return curr_pos;
            }

            if (i) {
                curr_pos += i;
            } else {
                curr_pos++;
            }
        }
    }
    return -1;
}

int main() 
{
    char str_arr[1002] = "";
    char old_word[10] = "Ling";
    char new_word[10] = "Cao";

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int len = strlen(str_arr);
    int old_word_len = strlen(old_word);
    int new_word_len = strlen(new_word);

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    int curr_pos = 0;
    int word_pos;
    while (curr_pos < len) 
    {
        word_pos = found_text(curr_pos, len-1, str_arr, old_word_len, old_word);
        if (word_pos == -1) 
            word_pos = len;
        
        for (int i = curr_pos; i < word_pos; i++) 
        {
            fprintf(f_out, "%c", str_arr[i]);
        }
        
        if (word_pos < len) 
        {
            for (int i = 0; i < new_word_len; i++) 
            {
                fprintf(f_out, "%c", new_word[i]);
            }    
            curr_pos = word_pos + old_word_len;
        } else {
            curr_pos = word_pos;
        }    
    } 
 
    fclose(f_out);

    return 0;
}
