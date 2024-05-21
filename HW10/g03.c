#include <stdio.h>
#include <string.h>

int loadDataFromFile(char str[])
{
    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 0;
    fscanf(f_in, "%[^\n]", str);
    fclose(f_in);
    return 1;
}

int saveDataToFile(char str[])
{
    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 0;
     
    int len = strlen(str);
    if (len) 
    {
        for(int i = 0; i < len -1; i++) 
        {
            if (str[i] == str[len-1]) 
                fprintf(f_out, " %d",  i);        
        }
    }

    fclose(f_out);
    return 1;
}

int main() 
{
    char str_arr[1000];

    if (!loadDataFromFile(str_arr))
        return 1;
    if (!saveDataToFile(str_arr))
        return 2;
    return 0;
}
