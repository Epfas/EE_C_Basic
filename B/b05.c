#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);

    long sum = 0;
    while (a > 0) 
    { 
        sum += a % 10;
        a /= 10;
    }
    printf("%d", sum);
}