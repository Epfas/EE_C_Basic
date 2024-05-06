#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

int getMin(int arr[], int count)
{
    int min;
    for (int i = 0; i < count; i++) 
    {
        if (i == 0 || arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main() 
{
    int count = 5;
    int arr[count];
    readData(arr, count);
    printf("%d", getMin(arr, count));
    
    return 0;
}