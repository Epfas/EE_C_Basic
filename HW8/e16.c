#include <stdio.h>

void readData(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        scanf("%d", &arr[i]);
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

int getMaxPos(int arr[][2], int count)
{
    int pos = -1;
    for (int i = 0; i < count; i++) 
    {
        if (i == 0 || arr[i][1] > arr[pos][1]) {
            pos = i;
        }
    }
    return pos;
}

int main() 
{
    int count = 10;
    int arr[count];
    int destArr[count][2];

    readData(arr, count);
    int destCount = processData(arr, count, destArr);
    printf("%d", destArr[getMaxPos(destArr, destCount)][0]);
    
    return 0;
}
