#include <stdio.h>

int main() {
	int x, max;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &x);
	    if ((max < x) || (i == 0)) 
	        max = x;
	}
	printf("%d", max);
	return 0;
}
