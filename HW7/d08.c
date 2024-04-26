#include <stdio.h>

void print_nums(int a, int b) 
{
    if (a == b) {
        printf(" %d", a);
        return;
    }
  
    if (a < b) {
        printf(" %d", a);
        print_nums( a+1, b);
    } else {
        printf(" %d", a);
        print_nums( a-1, b);
    }
}

int main() 
{
    int a, b;
    scanf("%d%d", &a, &b);
    print_nums(a, b);
    
    return 0;
}