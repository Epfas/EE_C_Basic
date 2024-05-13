#include <stdio.h>

const int SIZE = 10;

int find_max(int row, int arr[SIZE][SIZE]) 
{
    int max;
    for (int i=0; i<SIZE; i++) {
        if (i==0 || max < arr[row][i]) {
            max = arr[row][i];
        }
    }
    return max;   
}

int main() 
{
    int arr[SIZE][SIZE];
    
    for (int i = 0; i < SIZE; i++) 
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &arr[i][j]);

    int sum = 0;
    for (int i = 0; i < SIZE; i++) 
        sum += find_max(i, arr);
        
    printf("%d", sum);
    
    return 0;
}
