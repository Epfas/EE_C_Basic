#include <stdio.h>

int main(void) 
{
    int n; 
    scanf("%d", &n);
    
    int x0 = 0; 
    int x = 1;
    for (int i = 0; i < n; i++) {
        int f;
        if (i == 0) {
            f = 1;
        } else {
            f = x0 + x;
            x0 = x;
            x = f;
        }
        printf(" %d", f);
    }
}
