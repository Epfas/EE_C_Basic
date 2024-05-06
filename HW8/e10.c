#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

void shiftRight(int arr[], int count)
{
    int x = arr[count-1];
    for (int i = count -1; i > 0; i--) 
    {
        arr[i] = arr[i-1];
    }
    arr[0] = x;
}

void printData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        printf(" %d", arr[i]);
    }
}

int main() 
{
    int count = 12;
    int arr[count];
    readData(arr, count);

    for (int i = 1; i <= 4; i++) 
    {
        shiftRight(arr, count);
    }

    printData(arr, count);
    
    return 0;
}