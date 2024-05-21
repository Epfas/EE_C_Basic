#include <stdio.h>
#include <string.h>

char replace_char(char c) 
{
    if (c == 'a')
        return 'b';
    if (c == 'A')
        return 'B';    
    if (c == 'b')
        return 'a';
    if (c == 'B')
        return 'A';            
    return c;
}

int main() 
{
    char str_arr[1000];

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    
    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    int len = strlen(str_arr);
    for ( int i = 0; i < len; i++) {
        fprintf(f_out, "%c",  replace_char(str_arr[i]));        
    }
    fclose(f_out);

    return 0;
}
