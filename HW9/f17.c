#include <stdio.h>

int main() 
{
    int size = 5;
    int arr[size][size];
    
    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++)
            scanf("%d", &arr[i][j]);

    int sum = 0;
    for (int i = 0; i < size; i++) 
        sum += arr[i][i];
        
    printf("%d", sum);
    
    return 0;
}
