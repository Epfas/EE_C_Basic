#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

int sumPositive(int arr[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++) 
    {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() 
{
    int count = 10;
    int arr[count];
    readData(arr, count);
    
    printf("%d", sumPositive(arr, count));
    
    return 0;
}
