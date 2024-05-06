#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

void printData(int arr[][2], int count)
{
    for (int i = 0; i < count; i++) 
    {
        if (arr[i][1] > 1)
            printf("%d ", arr[i][0]);
    }
}

int processData(int arr[], int count, int destArr[][2])
{
    int destCount = 0;
    for (int i = 0; i < count; i++) 
    {
        int found = 0;
        for (int j = 0; j < destCount; j++) 
        {
            if (destArr[j][0] == arr[i]) 
            {
                found = 1;
                destArr[j][1]++;
                break;
            }
        }

        if (!found) {
            destArr[destCount][0] = arr[i];
            destArr[destCount][1] = 1;
            destCount++;
        }
    }
    return destCount;
}

int main() 
{
    int count = 10;
    int arr[count];
    int destArr[count][2];

    readData(arr, count);
    int destCount = processData(arr, count, destArr);
    printData(destArr, destCount);
    
    return 0;
}

