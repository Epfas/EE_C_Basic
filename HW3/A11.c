#include <stdio.h>

int main() {
	int x, min, max;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &x);
        if ((min > x) || (i == 0)) 
	        min = x;
        if ((max < x) || (i == 0)) 
	        max = x;
	}
	printf("%d", min + max);
	return 0;
}