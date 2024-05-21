#include <stdio.h>
#include <string.h>

int main() 
{
    int n;

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%d", &n);
    fclose(f_in);

    n = n >> 1;

    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;

    int x = 0; 
    for (int i = 0; i < n; i++) { 
        x += 2;
        if (x % 10 == 0) 
            x = 2;
        fprintf(f_out, "%c", 'A'+i);
        fprintf(f_out, "%d", x);
    }
    fclose(f_out);

    return 0;
}
