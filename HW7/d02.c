#include <stdio.h>

int calc_sum(int n) {
    if (n < 1)
        return 0;
    return calc_sum(n-1) + n;
}

int main(void) 
{
    int n;
    scanf("%d", &n);
    printf("%d", calc_sum(n));
    
    return 0;
}