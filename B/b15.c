#include <stdio.h>

int main(void) 
{
    int a;
    int count = 0;
    
    do 
    {
        scanf("%d", &a);
        if (a != 0 && a % 2 == 0)
            count++;
    }        
    while (a != 0);

    printf("%d", count);
}