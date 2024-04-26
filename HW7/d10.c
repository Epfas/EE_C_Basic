#include <stdio.h>

int is_prime (int n, int delitel) {
    if (n <= 1)  
        return 0;
    if (delitel <= 1) 
        delitel = 2;    
    if (delitel == n) 
        return 1;
    if (n % delitel == 0) 
       return 0;    
    return is_prime(n, delitel +1);
}

int main(void) 
{
    int a;
    scanf("%d", &a);
    (is_prime(a, 1)) ? printf("YES") : printf("NO");
}
