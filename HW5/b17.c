#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    for (int i = 10; i <= a; i++) 
    {
        int sum = 0;
        int mult = 1;
        int digit;
        int x = i;
        
        while (x > 0) {
            digit = x % 10;
            sum += digit;
            mult *= digit;
            x /= 10;
        }
        
        if (sum == mult) {
            printf(" %d", i);
        }
    }
}