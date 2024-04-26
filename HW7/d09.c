#include <stdio.h>

int sum_digits(int n) 
{
    if (n == 0)
        return 0;
    return sum_digits(n/10) + n % 10;
}

int main() 
{
    int n;
    scanf("%d", &n);
    printf("%d", sum_digits(n));
    
    return 0;
}