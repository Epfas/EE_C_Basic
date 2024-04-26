#include <stdio.h>

void print_simple(int n, int div) 
{
    if (div < 2)
        div = 2;
        
    if (n % div == 0) {
        printf(" %d", div);
        n /= div;
    } else {
        div++;
    }
    
    if (n > 1) 
        print_simple(n, div);
}

int main() 
{
    int n;
    scanf("%d", &n);
    print_simple(n, 1);
    
    return 0;
}
