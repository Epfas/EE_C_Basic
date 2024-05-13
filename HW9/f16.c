#include <stdio.h>

int main() 
{
    char hor;
    int vert;
    
    scanf("%c%d", &hor, &vert);
    if (hor >= 'a' && hor <= 'h') 
        hor = hor - 'a' + 'A'; 
    hor = hor - 'A' +1;

    int isWhite = ((vert % 2) + hor) % 2;
    (isWhite) ? printf("WHITE") : printf("BLACK");

    return 0;
}
