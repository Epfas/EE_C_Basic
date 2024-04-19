#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);

    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    
    if (sum == 10) {
        printf("YES");
    } else {
        printf("NO");
    }
}