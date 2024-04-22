#include <stdio.h>

void print_simple(int n) 
{
    int div = 2;
    while (n > 1) 
    {
        if (n % div == 0) 
        {
            printf(" %d", div);
            n /= div;
        } else {
            div++;
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    print_simple(n);
    
    return 0;
}