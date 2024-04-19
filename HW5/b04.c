#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);

    if (a < 100 || a > 999) {
        printf("NO");
    } else {
        printf("YES");
    }
}