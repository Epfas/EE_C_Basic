#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    int nonPrime = 1;
    if (a > 1) {
        nonPrime = 0;
        int i = 2;
        while (nonPrime == 0 && i < a) 
        {
            if (a % i == 0) {
                nonPrime++; 
            } else {
                i++;
            }
        }
    }
    
    if (nonPrime == 0) {
        printf("YES");
    } else {
        printf("NO");
    }
}
