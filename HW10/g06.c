#include <stdio.h>
#include <string.h>

int is_palindrom(char str[]) {
    int len = strlen(str);
    if (!len)
        return 0;

    char str2[1000] = "";
    int cnt = 0;

    for ( int i = 0; i < len; i++) 
    {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') 
        {
            str2[cnt] = str[i];
            cnt++;
        }
    }

    if (cnt <1)
        return 0;

    for ( int i = 0; i < cnt/2; i++) 
    {
        if (str2[i] != str2[cnt-i-1])
            return 0;        
    }
    return 1;
}

int main() {
    char str_arr[1000];

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    
    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;
    if (is_palindrom(str_arr)) {
        fprintf(f_out, "YES");        
    } else {
        fprintf(f_out, "NO");        
    }
    fclose(f_out);

    return 0;
}
