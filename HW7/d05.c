#include <stdio.h>

void convert_to_bin(int n) 
{
    if (n/2)    
        convert_to_bin(n/2);
    printf("%d", n % 2);
}

int main() {
    int n;
    scanf("%d", &n);
    convert_to_bin(n);
    
    return 0;
}
