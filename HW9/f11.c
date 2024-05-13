#include <stdio.h>

int main()
{
    int size = 30;
    int arr[size];
    int pos1 = -1;
    int pos2 = -1;
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (pos1 == -1 || arr[i] < arr[pos1]) 
            pos1 = i;
    }
    
    for (int i = 0; i < size; i++) {
        if (i != pos1)
            if (pos2 == -1 || arr[i] < arr[pos2]) 
                pos2 = i;
    }
    
    (pos1 < pos2) ? printf("%d %d", pos1, pos2) : printf("%d %d", pos2, pos1);
    
    return 0;
}
