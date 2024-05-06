#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

void printData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        printf(" %d", arr[i]);
    }
}

int migrateData(int sourceArr[], int sourceCount, int destArr[])
{
    int destCount = 0;
    for (int i = 0; i < sourceCount; i++) 
    {
        if (((sourceArr[i] % 100) / 10) == 0) {
            destArr[destCount++] = sourceArr[i];
        }
    }
    return destCount;
}

int main() 
{
    int count = 10;
    int arr[count];
    int resArr[count];

    readData(arr, count);
    int resCount = migrateData(arr, count, resArr);
    printData(resArr, resCount);
    
    return 0;
}
