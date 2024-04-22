#include <stdio.h>

int grow_up (int n) 
{
    if (n<10)
        return 1;
        
    int last_digit = n % 10;
    int curr_digit;
    n /= 10;
    while (n) 
    {
        curr_digit = n % 10;
        if (curr_digit >= last_digit) {
            return 0;
        }
        last_digit = curr_digit;
        n /= 10;
    }
    return 1;
}

int main(void) 
{
    int x; 
    scanf("%d", &x);
    (grow_up(x)) ? printf("YES") : printf("NO");

    return 0;
}
