#include <stdio.h>
#include <string.h>
#include <math.h>

int get_lines(int sum) 
{
    if (sum > 0) 
    {
        int d = 1 + 8 * sum;
        float ds = sqrt(d);
        if (ds - trunc(ds) > 0.000001)  
            return 0;
        
        int dsx = ds;
        if (dsx % 2) 
            return dsx >> 1;
    }
    return 0;
}


int main() 
{
    int count = 0;

    FILE *f_in = fopen("input.txt", "rb");
    if (f_in == NULL) 
        return 1;
    while (!feof(f_in))        
        if (getc(f_in) == '*') 
            count++;
    
    fclose(f_in);
    
    int lines = get_lines(count);

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    if (lines) 
    {
        for (int i = 0; i<lines; i++) 
        {
            for (int j = 1; j<lines-i; j++) 
                fprintf(f_out, " ");
            fprintf(f_out, "*");
            for (int j = 0; j<i; j++) 
                fprintf(f_out, " *");
            fprintf(f_out, "\n");
        }
    } else 
        fprintf(f_out, "NO");
    fclose(f_out);

    return 0;
}
