#include <stdio.h>

int main(void) 
{
    int a, b;
    scanf("%d%d", &a, &b);
    
    if (a < -100) 
        a = -100;
    if (a > 100) 
        a = 100;
    if (b < a) 
        b = a;
    if (b > 100) 
        b = 100;

    printf("%d", a*a);
    for (int i = a+1; i <= b; i++) 
    { 
        printf(" %d", i*i);
    }
}
