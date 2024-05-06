#include <stdio.h>

int main() 
{
    int arr_len = 10;
    int arr[arr_len];
    int neg[arr_len];
    int pos[arr_len];
    int neg_next_no = 0;
    int pos_next_no = 0;

    for (int i = 0; i < arr_len; i++) 
    {
        scanf("%d", &arr[i]);
        
        if (arr[i] > 0) {    
            pos[pos_next_no++] = arr[i];
        }
        if (arr[i] < 0) {    
            neg[neg_next_no++] = arr[i];
        }
    }

    for (int i = 0; i < pos_next_no; i++) 
    {
        printf(" %d", pos[i]);
    }
    for (int i = 0; i < neg_next_no; i++) 
    {
        printf(" %d", neg[i]);
    }
    return 0;
}
