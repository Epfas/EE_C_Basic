#include <stdio.h>

const int SIZE = 5;

float avg_diag(int arr[SIZE][SIZE]) 
{
    float sum = 0.0;
    for (int i=0; i<SIZE; i++) {
        sum += (float)arr[i][i];
    }
    return sum / SIZE;   
}

int main() 
{
    int arr[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) 
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &arr[i][j]);

    float avg = avg_diag(arr);
    
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) 
        for (int j = 0; j < SIZE; j++)
            if (arr[i][j] > 0 && avg < arr[i][j])
                cnt++;
        
    printf("%d", cnt);
    
    return 0;
}
