#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void htower(int n,int a,int c);
int count = 0;

int main(void) {
	int  n = 0;
	scanf("%d", &n);
	
	printf("%d\n", (int)pow(2,n)-1);
	htower(n, 1, 3);
	return 0;
}

void htower(int n, int a, int c) {
	int b;
	if (n == 1) {
		printf("%d %d\n", a, c);
	}
	else {
		b = 6 - a - c;
		htower(n - 1, a, b);
		printf("%d %d\n", a, c);
		htower(n - 1, b, c);
	}
}