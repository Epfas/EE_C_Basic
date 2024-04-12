#include <stdio.h>

int main() {
	int x1, x2;
	scanf("%d%d", &x1, &x2);

    if (x1 == x2) {
	printf("Equal");
    } else if (x1 > x2) {
        printf("Above");
    } else {
        printf("Less");
    }
	return 0;
}
