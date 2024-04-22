#include <stdio.h>

int func(int a) {
    return (1 + a) * a / 2; 
}

int main() 
{
    int a = 0;
    scanf("%d", &a);

    printf("%d", func(a));
    
    return 0;
}
