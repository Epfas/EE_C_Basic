#include <stdio.h>

int main() {
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	float k, b, kx, ky;
	
	if (x1 == x2) {
		k = 0;
	} else {
		kx = (x1 - x2);
		ky = (y1 - y2);
		k = ky / kx;
	}
	b = y1 - k * x1;  
	  
	printf("%.2f %.2f", k, b);
	return 0;
}
