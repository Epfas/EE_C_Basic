#include <stdio.h>

int count_x_converted_to_p(int n, int p, int x) 
{
    if (p < 2)
        p = 2;
    if (x >= p) 
        x = p -1;
    int count = 0;
    if (n) {
        count += count_x_converted_to_p(n / p, p, x);
    }
    if (n % p == x)
        count++;
    return count;
}

int main() 
{
    int n, p = 2;
    scanf("%d", &n);
    
    printf("%d", count_x_converted_to_p(n, p, 1));     

    return 0;
}
