#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    int isEqual = 0;
    int currentDigit, lastDigit = a % 10;
    a /= 10;
    while (a > 0 && !isEqual) 
    {
        currentDigit = a % 10;
        if (lastDigit == currentDigit) 
            isEqual++;
        lastDigit = currentDigit;
        a /= 10;
    }

    if (isEqual) {
        printf("YES");
    } else {
        printf("NO");    
    }
}