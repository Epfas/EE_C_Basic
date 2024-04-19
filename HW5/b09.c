#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    int isEven = 1;
    while (a > 0 && isEven) 
    {
        int digit = a % 10;
        isEven = isEven && (digit % 2 == 0); 
        a /= 10;
    }

    if (isEven) {
        printf("YES");
    } else {
        printf("NO");    
    }
}