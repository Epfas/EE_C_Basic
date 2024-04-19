#include <stdio.h>

int main(void) 
{
    int n;
    scanf("%d", &n);
    if (n < 1) 
        n = 1;
    if (n > 100) 
        n = 100;

    for (int i = 1; i <= n; i++) 
	{ 
        printf("%d %d %d\n", i, i*i, i*i*i);
    }
}
