#include <stdio.h>

int main() {
	int x1, x2, x3;
	scanf("%d%d%d", &x1, &x2, &x3);

    if ((x1 <= x2) && (x2 <= x3) && (x1 != x3)) {
	    printf("YES");
    } else {
        printf("NO");
    }
	return 0;
}
