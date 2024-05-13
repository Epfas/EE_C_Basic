#include <stdio.h>

void read (int arr[]) 
{
    char c;
    while ((c=getchar()) != '\n') 
    {
        if (c>='0' && c<='9') {
            arr[c - '0']++;
        }
    }
}

int main()
{
    
    int arr[10]={0,0,0,0,0,0,0,0,0,0};

    read(arr);    
    
    for (int i=0; i<10; i++) {
        if (arr[i])
            printf("%d %d\n", i, arr[i]);
    }

    return 0;
}
