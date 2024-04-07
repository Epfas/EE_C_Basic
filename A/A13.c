#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	int res = 1;
	
	while (a > 0) {
		res *= a % 10;
		a = a / 10;
	}
	
	printf("%d", res);
	return 0;
}
