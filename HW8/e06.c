#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

int sumData(int arr[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++) 
    {
        sum += arr[i];
    }
    return sum;
}

int main() 
{
    int count = 12;
    int arr[count];
    readData(arr, count);
    
    printf("%.2f", sumData(arr, count)/(float)count);
    
    return 0;
}
