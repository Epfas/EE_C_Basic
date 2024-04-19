#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    int minDigit = 9, maxDigit = 0;
    if (a == 0) 
        minDigit = 0;
    while (a > 0) 
    {
        int digit = a % 10;
        if (minDigit > digit)
            minDigit = digit;
        if (maxDigit < digit)
            maxDigit = digit;
        a /= 10;
    }

    printf("%d %d", minDigit, maxDigit);
}