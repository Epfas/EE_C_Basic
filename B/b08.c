#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    int count = 0;
    while (a > 0 && count < 2) 
    {
        if (a % 10 == 9) 
            count++;
        a /= 10;
    }

    if (count == 1) {
        printf("YES");
    } else {
        printf("NO");    
    }
}