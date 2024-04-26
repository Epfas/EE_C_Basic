#include <stdio.h>

int acounter(void) 
{
    char c;
    scanf("%c", &c);
    if (c == '.' || c == 0)   
        return 0;
    return (c == 'a') + acounter();
}

int main() 
{
    printf("%d", acounter());
    return 0;
}
