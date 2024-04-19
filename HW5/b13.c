#include <stdio.h>

int main(void) 
{
    int a;
    scanf("%d", &a);
    
    int arr[2] = {0, 0};
    while (a > 0) 
    {
        arr[a % 2]++;
        a /= 10;
    }

    printf("%d %d", arr[0], arr[1]);
}