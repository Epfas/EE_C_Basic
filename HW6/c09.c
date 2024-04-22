#include <stdio.h>

long long unsigned int factorial(int n) 
{
    if (!n) 
        return 0;
    long long unsigned int res = 1;    
    for (int i = 2; i <= n; i++) 
    {
        res *= i;
    }
    return res;
}

int main() 
{
    int n;
    scanf("%d", &n);
    printf("%llu", factorial(n));
    
    return 0;
}