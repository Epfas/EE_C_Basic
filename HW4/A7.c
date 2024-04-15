#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if (a > b) {
		int c = a;
		a = b;
		b = c;
	}
		
	printf("%d %d", a, b);
	return 0;
}
