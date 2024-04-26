#include <stdio.h>

void print_unpaired() {
    int n;
    scanf("%d", &n);
    if (!n) 
        return;
        
    if (n % 2) {
        printf(" %d", n);
    }

    print_unpaired();
}

int main() 
{
    print_unpaired();
    return 0;
}
