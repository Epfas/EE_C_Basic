#include <stdio.h>

int is2pow(int n) 
{
    if (n == 1)
        return 1;
    if (n % 2)
        return 0;
    if (n/2)    
        return is2pow(n/2);
    return 1;
}

int main() 
{
    int n;
    scanf("%d", &n);
    (is2pow(n)) ? printf("YES") : printf("NO");
    return 0;
}
