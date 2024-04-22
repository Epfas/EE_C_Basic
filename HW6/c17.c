#include <stdio.h>

int is_happy_number (int n) 
{
    if (n < 10) 
        return 1;
        
    int sum = 0;
    int mult = 1;
    while (n) 
    {
        sum += n % 10;
        mult *= n % 10;
        n /= 10;
    }
    return sum == mult;
}

int main(void) 
{
    int a;
    scanf("%d", &a);
    (is_happy_number(a)) ? printf("YES") : printf("NO");
}