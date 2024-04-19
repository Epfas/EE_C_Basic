#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    int a2 = a / 10;
    int coef = 1;
    while (a2 > 0) 
    {
        coef *= 10;
        a2 /= 10;
    }

    int res = 0;
    while (a > 0) 
    {
        res += (a % 10) * coef;
        coef /= 10;
        a /= 10;
    }

    printf("%d", res);
}