#include <stdio.h>

int main() 
{
    do 
    {
        char c;
        scanf("%c", &c);
        if (c == 0 || c == '.') 
            break;
        
        if (c >= 65 && c <= 90) 
            c += 32;
        printf("%c", c);
    }
    while (1);
    
    return 0;
}
