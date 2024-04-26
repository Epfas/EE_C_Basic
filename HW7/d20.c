#include <stdio.h>

long long int recurs_power(int n, int p) 
{
    if (!p)
        return 1;
    if (!n)
        return 0;
    return n * recurs_power(n, p-1);  
}

int main() 
{
    int n, p;
    scanf("%d%d", &n, &p);
    printf("%lli", recurs_power(n, p));
    return 0;
}
