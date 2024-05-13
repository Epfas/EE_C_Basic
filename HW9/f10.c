#include <stdio.h>

int read_line (char arr[]) {
    int size = 0;
    char c;
    
    while ((c = getchar()) != '.') 
    {
        arr[size++] = c;
    } 
    return size;
}

void compress_line(char str[], int size)
{
    int cnt = 0;
    char c = 0;
    
    for (int i = 0; i < size; i++) 
    {
        if (c != str[i] && cnt) 
        {
            printf("%c%d", c, cnt);
            cnt = 0;
        }
        c = str[i];
        cnt++;
    }    
    
    if (cnt) 
        printf("%c%d", c, cnt);
}

int main()
{
    char str[1000];
    int size = 0;

    size = read_line(str);
    compress_line(str, size);

    return 0;
}
