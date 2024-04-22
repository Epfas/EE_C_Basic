#include <stdio.h>

int func(int a) 
{
    if (a < -2)
        return 4;
    if (a >= 2)
        return a*a + 4*a + 5;
    return a * a; 
}

int main() 
{
    int count = 0;
    int x = 0;
    int maxValue = 0;
    do 
    {
        scanf("%d", &x);
        if (x != 0) 
        {
            count++;
            x = func(x);
            if (count == 1 || x > maxValue) 
                maxValue = x;
        }
    }
    while (x != 0);
    
    if (count == 0) {
        printf("NO DATA");
    } else {
        printf("%d", maxValue);
    }
    
    return 0;
}