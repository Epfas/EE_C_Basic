#include <stdio.h>

int max_find(int max) 
{
    int n;
    scanf("%d", &n);
    if (!n) 
        return max;
    if ((n > max) || !max)
        max = n;
    return max_find(max);
}

int main() {
    printf("%d", max_find(0));
    return 0;
}
