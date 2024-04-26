#include <stdio.h>

void print_nums(int n) 
{
    printf(" %d", n);
    if (n > 1) 
      print_nums(n-1);
}

int main() {
    int n;
    scanf("%d", &n);
    print_nums(n);
    
    return 0;
}