#include <stdio.h>

int digitsSumIsUnpaired (int n) 
{
    int digitSum = 0;
    while (n) 
    {
        digitSum += n % 10;
        n /= 10;
    }
    return digitSum % 2;
}

int main(void) 
{
    int x; 
    scanf("%d", &x);
    (digitsSumIsUnpaired(x)) ? printf("NO"):printf("YES");

    return 0;
}