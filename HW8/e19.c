#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    
    int x = n;
    int arr_len = 0;
    while (x) 
    {
        arr_len++;
        x /= 10;
    }

    short arr[arr_len];
    for (int i = 0; i < arr_len; i++) 
    {
        arr[arr_len - i -1] = n % 10;
        n /= 10;
    }
    
    for (int i = 0; i < arr_len; i++) 
    {
        printf(" %d", arr[i]);
    }
    return 0;
}
