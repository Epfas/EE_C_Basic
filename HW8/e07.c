#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

void printDataInverse(int arr[], int count)
{
    int middle = count / 2;

    for (int i = 0; i < count; i++) 
    {
        printf(" %d", arr[middle*(i / middle) + middle - 1 - i % middle]);
    }
}

int main() 
{
    int count = 10;
    int arr[count];
    readData(arr, count);
    printDataInverse(arr, count);

    return 0;
}
