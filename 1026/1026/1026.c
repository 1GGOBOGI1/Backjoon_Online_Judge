#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void) {

	int size=0, result = 0, *A, *B, *b;
	scanf("%d", &size);
	
	A = (int*)malloc(sizeof(int)*size);
	B = (int*)malloc(sizeof(int)*size);
	b = (int*)malloc(sizeof(int)*size);

	for (int i = 0; i < size;i++) {
		scanf("%d", (A+i));
	}
	
	for (int i = 0; i < size;i++) {
		scanf("%d", (B+i));
	}
	b = B;

	for (int i = 0; i < size;i++) {
		int tmp, min;
		min = i;
		for (int j = i + 1; j < size;j++) {
			if (*(A + j)<*(A + min)) min = j;
		}
		tmp = A[i];
		A[i] = A[min];
		A[min] = tmp;
	}

	for (int i = 0; i < size;i++) {
		int tmp, max;
		max = i;
		for (int j = i+1; j < size;j++) {
			if (*(b+j)>*(b+max)) max = j;
		}
		tmp = b[i];
		b[i] = b[max];
		b[max] = tmp;
	}

	for (int i = 0; i < size; i++) {
		result = result + *(A + i)*(*(B + i));
	}
	printf("%d", result);
	
	free(A);
	free(B);
	return 0;
}