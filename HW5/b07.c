#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    int isEqual = 0;
    int digit1, digitX, x;
    while (a > 0 && !isEqual) 
    {
        digit1 = a % 10;
        a /= 10;
        x = a;
        while (x > 0 && !isEqual)
        {
            digitX = x % 10;
            x /= 10;
            if (digit1 == digitX) 
                isEqual++;
        }
    }

    if (isEqual) {
        printf("YES");
    } else {
        printf("NO");    
    }
}