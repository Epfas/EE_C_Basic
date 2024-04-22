#include <stdio.h>

int digit_to_num(char c) 
{
    if (c >= 48 && c <= 57)
        return c - 48;
    return 0;
}

int main() 
{
    int sum = 0;
    char c;
    while ((c = getchar()) != '.')
    {
        sum += digit_to_num(c);
    }
    
    printf("%d", sum);
    
    return 0;
}