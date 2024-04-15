#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	int sum = 0;
	
	while (a >= 10) {
		sum += a % 10;
		a = a / 10;
	}
	sum += a;
	
	printf("%d", sum);
	return 0;
}
