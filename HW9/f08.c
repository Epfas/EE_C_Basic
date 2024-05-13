#include <stdio.h>

int main()
{
    int size = 0;
    int min, max;
    int x = 0;
    int res = 0;

    do 
    {
        scanf("%d", &x);
        if (x) 
        {
            if (!size || max < x)
                max = x;     
            if (!size || min > x)
                min = x;                
            res^= x;
            size++;
        }
    } 
    while (x && size < 1000);

    for (int i = min; i <= max; i++)
        res ^= i;

    printf("%d", res);
    
    return 0;
}
