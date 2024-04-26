#include <stdio.h>

int akkerman(int m, int n) 
{
    if (!m)
        return n+1;
    if (!n)
        return akkerman(m -1, 1);
    return akkerman(m-1, akkerman(m, n-1));
}

int main() 
{
    int n, m;
    scanf("%d%d", &m, &n);
    printf("%d", akkerman(m, n));
    return 0;
}