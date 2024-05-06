#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

void sortDataFor1Iteration(int arr[], int count, int iterationNo)
{
    for (int i = 0; i < count - iterationNo; i++) 
    {
        if (arr[i] > arr[i+1]) {
            int x = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = x;
        }
    }
}

int main() 
{
    int count = 10;
    int arr[count];
    readData(arr, count);

    for (int i = 1; i <= 2; i++) 
    {
        sortDataFor1Iteration(arr, count, i);
    }
        
    printf("%d", arr[count-1] + arr[count-2]);
    
    return 0;
}