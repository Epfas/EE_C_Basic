#include <stdio.h>
#include <string.h>

int is_palindrom(char string[]) 
{
    int len = strlen(string);
    if (!len)
        return 0;
        
    int letters_size = 26;
    int letters_cnt[letters_size];
    for (int i = 0; i < letters_size; i++) 
        letters_cnt[i] = 0;

    int res_len = 0;
    for (int i = 0; i < len; i++) 
        if (string[i] >= 'a' && string[i] <= 'z') 
        {
            letters_cnt[string[i] - 'a']++;
            res_len++; 
        }
    
    if (!res_len)
        return 0;
        
    int single_count = 0;  
    for (int i = 0; i < letters_size; i++) 
    {
        if (letters_cnt[i] %2) 
            single_count++;
        if (single_count > 1)
            return 0;
    }
    return 1;
}

int main() 
{
    char str_arr[1002] = "";
    
    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    (is_palindrom(str_arr)) ? printf("YES") : printf("NO");
  
    return 0;
}
