#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    int count = 0; 
    int curr_n = 0;
    for (int i = 1; i <= n; i++, count--) {
        if (!count) {
            curr_n++;
            count = curr_n;
        }
        printf(" %d", curr_n);
    }    
    
    return 0;
}
