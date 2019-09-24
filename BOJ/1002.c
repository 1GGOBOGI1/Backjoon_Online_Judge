#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void) {
	int num;
	scanf("%d", &num);
	for (int i = 0;i < num;i++) {
		int x1, y1, r1, x2, y2, r2;

		scanf("%d %d %d %d %d %d", &x1, &r1, &r1, &x2, &y2, &r2);
		if ((x1 == y1) && (x2 == y2)) {
			if (r1 == r2)printf(-1);
			else return printf(0);
		}
		else {

		}
	}
	return 0;
}
