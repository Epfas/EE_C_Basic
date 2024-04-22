#include <stdio.h>

int power(int n, int pwr) {
    if (pwr == 0) 
      return 1;
    
    int res = n;
    for (int i = 1; i < pwr; i++)
        res *= n;
    return res; 
}

int main() 
{
    int a, pwr;
    scanf("%d%d", &a, &pwr);
    if (pwr < 0) 
        pwr = 0;
    
    printf("%d", power(a, pwr));
    
    return 0;
}
