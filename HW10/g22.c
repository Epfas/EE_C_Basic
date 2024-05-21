#include <stdio.h>
#include <string.h>

int soundex(int len, char str[], char res_str[]) 
{
    int res_len = 0;
    if (len) 
    {
        int last_x = 0;
        for (int i = 0; i < len; i++) 
        {
            if (str[i] >= 'a' && str[i] <= 'z') 
            {
                if (!res_len) 
                {
                    res_str[0] = str[i];
                    res_len = 1;
                } else {
                    int x = 0;
                    if (str[i] == 'b' || str[i] == 'f' || str[i] == 'p' || str[i] == 'v') 
                    {
                        x = 1;
                    } 
                    else if (str[i] == 'c' || str[i] == 'g' || str[i] == 'j' || str[i] == 'k' ||
                            str[i] == 'q' || str[i] == 's' || str[i] == 'x' || str[i] == 'z')  
                    {
                        x = 2;
                    } 
                    else if (str[i] == 'd' || str[i] == 't') 
                    {
                        x = 3;
                    } 
                    else if (str[i] == 'l') 
                    {
                        x = 4;
                    } 
                    else if (str[i] == 'm' || str[i] == 'n') 
                    {
                        x = 5;    
                    } 
                    else if (str[i] == 'r') 
                    {
                        x = 6;
                    }

                    if (x) 
                    {
                        if (last_x != x || !last_x) 
                        {
                            res_str[res_len] = x + '0';
                            res_len++;
                        }
                        last_x = x;
                    }
                }
            }

            if (res_len && str[i] == ' ') 
                break;
        }
    }

    if (res_len) 
    {
        if (res_len < 4) 
        {
            for (int i = res_len; i < 4; i++) 
            {
                res_str[res_len] = '0';
                res_len++;
            }
        }
    
        if (res_len > 4) 
        {
            res_str[4] = 0;
            res_len = 4;
        }
    }
    
    return res_len;
}


int main() 
{
    char str_arr[25] = "";
    char res_arr[25] = "";
    
    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;

    fscanf(f_in, "%[^\n]", &str_arr);
    int len = strlen(str_arr);
    fclose(f_in);
    
    int res_len = soundex(len, str_arr, res_arr);

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    for (int i = 0; i < res_len; i++) 
        fprintf(f_out, "%c", res_arr[i]);

    fclose(f_out);

    return 0;
}
