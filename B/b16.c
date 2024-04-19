#include <stdio.h>

int main(void) 
{
    int a, b;
    scanf("%d%d", &a, &b);
    
    while (a != 0 && b != 0) 
    {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    printf("%d", a + b);
}