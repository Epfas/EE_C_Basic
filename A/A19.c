#include <stdio.h>

int main() {
	int x1, x2, x3;
	scanf("%d%d%d", &x1, &x2, &x3);

    if ((x1 > 0) && (x2 > 0) && (x3 > 0) &&
	    (x1 + x2 > x3) && (x1 + x3 > x2) && (x3 + x2 > x1)) 
	{
		printf("YES");
    } else {
        printf("NO");
    }
	return 0;
}
