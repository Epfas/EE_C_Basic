#include <stdio.h>

int bracketOffset(char c) 
{
    if (c == '(')
        return 1;
    if (c == ')')
        return -1;
    return 0;
}

int main() 
{
    int count = 0;
    char c;
    while ((c = getchar()) != '.')
    {
        count += bracketOffset(c);
        if (count < 0)
            break;
    }
    
    (count == 0) ? printf("YES") : printf("NO");
    
    return 0;
}