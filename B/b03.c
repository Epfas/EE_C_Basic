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

    long sum = 0;

    for (int i = a; i <= b; i++) 
    { 
        sum += i*i;
    }
    printf("%d", sum);
}
