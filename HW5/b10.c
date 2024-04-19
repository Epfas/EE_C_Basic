#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    int isGrowing = 1;
    int rightDigit = a % 10;
    a /= 10;
    while (a > 0 && isGrowing) 
    {
        int leftDigit = a % 10;
        isGrowing = isGrowing && (rightDigit > leftDigit); 
        rightDigit = leftDigit;
        a /= 10;
    }

    if (isGrowing) {
        printf("YES");
    } else {
        printf("NO");    
    }
}