#include <stdio.h>

char upperCase(char c) 
{
    if (c >= 97 && c <= 122) 
        c -= 32;
    return c;
}

int main() {
    char c;
    while ((c = getchar()) != '.')
    {
        c = upperCase(c);
        putchar(c);
    }
    
    return 0;
}