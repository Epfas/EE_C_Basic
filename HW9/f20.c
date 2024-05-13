#include <stdio.h>

int trasn_mult(int n, int unpair) 
{
    int mult = 1;
    int x;
    
    while (n) 
    {
        x = n %10;
        if (x % 2 != unpair)
            mult *= x;
        n /= 10;
    }
    return mult;   
}

int main() 
{
    int size = 10;
    int arr[size];
    int cnt = 0;

    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
        cnt += arr[i] % 2;
    }

    int unpair = cnt >= (size / 2);
    for (int i = 0; i < size; i++) 
    {    
        if (arr[i] % 2 != unpair) 
            arr[i] = trasn_mult(arr[i], unpair);
        printf(" %d", arr[i]);
    }

    return 0;
}
