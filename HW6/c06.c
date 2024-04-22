#include <stdio.h>

long long unsigned int power(int n, int pwr) 
{
    if (pwr == 0) 
      return 1;
    
    long long unsigned int res = (long long unsigned int)n;
    for (int i = 1; i < pwr; i++)
        res *= n;
    return res; 
}

int main() 
{
    int a = 0;
    scanf("%d", &a);
	
    printf("%llu", power(2, a - 1));
    
    return 0;
}