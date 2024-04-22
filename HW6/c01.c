#include <stdio.h>

int absNumber(int n) {
    if (n < 0) 
      n *= -1;
    return n; 
}

int main() 
{
    int a;
    scanf("%d", &a);

    printf("%d", absNumber(a));
    
    return 0;
}
