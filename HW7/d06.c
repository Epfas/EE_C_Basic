#include <stdio.h>

void reverse_string() 
{
    char c;
    scanf("%c", &c);
    if (c == '.' || c == 0)   
        return;
    reverse_string();    
    printf("%c", c);
}

int main() 
{
    reverse_string();
    
    return 0;
}
