#include <stdio.h>

int main() {
	int x, min;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &x);
	    if ((min > x) || (i == 0)) 
	        min = x;
	}
	printf("%d", min);
	return 0;
}