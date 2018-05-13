#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main(void) {
	int num, result = 0;

	scanf("%d", &num);

	if (num < 100) result = num;
	else {
		result = 99;
		for (int i = 100; i <= num;i++) {
			if (((i / 100) - (i / 10) % 10) == ((i / 10) % 10 - i % 10)) result++;
		}
	}
	printf("%d", result);
	return 0;
}

