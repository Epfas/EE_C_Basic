#include <stdio.h>

int main() 
{
    int arr_len = 10;
    int arr[arr_len];
    int min_pos = 0;
    int max_pos = 0;
    
    for (int i = 0; i < arr_len; i++) 
    {
        scanf("%d", &arr[i]);
        if (i == 0 || arr[i] < arr[min_pos]) 
            min_pos = i;
        if (i == 0 || arr[i] > arr[max_pos]) 
            max_pos = i;
    }
    
    printf("%d %d %d %d", max_pos+1, arr[max_pos], min_pos+1, arr[min_pos]);
    
    return 0;
}
