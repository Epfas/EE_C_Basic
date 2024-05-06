#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

void sortData(int arr[], int count)
{
    int mid_pos = count / 2;

    for (int i = 0; i < mid_pos; i++) 
    {
        int is_replaced = 0;
        for (int j = 1; j < mid_pos -i; j++) 
        {
            if (arr[j] < arr[j-1]) {
                int x = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = x;
                is_replaced = 1;
            }
        }
        if (!is_replaced)
            break;
    }

    for (int i = mid_pos; i < count; i++) 
    {
        int is_replaced = 0;
        for (int j = mid_pos +1; j < count -i + mid_pos; j++) 
        {
            if (arr[j] > arr[j-1]) {
                int x = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = x;
                is_replaced = 1;
            }
        }
        if (!is_replaced)
            break;
    }
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
    int count = 10;
    int arr[count];
    readData(arr, count);
    sortData(arr, count);
    printData(arr, count);
    
    return 0;
}