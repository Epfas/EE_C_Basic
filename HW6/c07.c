#include <stdio.h>

void convertToP(int n, int p) {
    if (n) {
        convertToP(n / p, p);
    }
    printf("%d", n % p);
}

int main() 
{
    int n, p;
    scanf("%d%d", &n, &p);
    
    convertToP(n, p);     

    return 0;
}