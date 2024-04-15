#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	int res = 0;
	
	while (a > 0 && res < 9) {
		int digit = a % 10;
		a = a / 10;
		if (digit > res)
			res = digit;
	}

	printf("%d", res);
	return 0;
}

