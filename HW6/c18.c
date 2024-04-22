#include <stdio.h>

int is_digit(char c) 
{
    return c >= 48 && c <= 57;
}

int main() 
{
    int count = 0;
    char c;
    while ((c = getchar()) != '.')
    {
        if (is_digit(c)) 
            count++;
    }
    
    printf("%d", count);
    
    return 0;
}