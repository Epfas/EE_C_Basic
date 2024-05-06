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
    int tripple = count / 3;

    for (int i = 0; i < count; i++) 
    {
        printf(" %d", arr[tripple*(i / tripple) + tripple - 1 - i % tripple]);
    }
}

int main() 
{
    int count = 12;
    int arr[count];
    readData(arr, count);
    printDataInverse(arr, count);
    
    return 0;
}
