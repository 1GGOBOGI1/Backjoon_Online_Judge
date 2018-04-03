#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	long long a = 0, b = 0, c = 0;
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", a + b + c);
	return 0;
}