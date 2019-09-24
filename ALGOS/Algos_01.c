#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b);
int rbinsearch(int card[], int item, int left, int right);
int main(void) {
	int N = 0, n = 0, M = 0, m = 0, *A, *B;
	
	scanf("%d", &N);
	A = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N;i++) {
		scanf("%d", (A + i));
	}
	
	qsort(A, N, 4, compare);

	scanf("%d", &M);
	B = (int*)malloc(sizeof(int)*M);
	for (int i = 0;i < M;i++) {
		scanf("%d", (B + i));
	}

	for (int i = 0; i < M; i++) {
		printf("%d ",rbinsearch(A, *(B + i), 0, N - 1));
	}


	free(A);
	free(B);
	return 0;
}

int compare(const void *a, const void *b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2) return -1;
	else if (num1 > num2) return 1;
	else return 0;
}

int rbinsearch(int card[], int item, int left, int right) {
	int middle;
	if (left <= right) {
		middle = (left + right) / 2;
		if (card[middle] < item) return rbinsearch(card, item, middle + 1, right);
		else if (card[middle] > item) return rbinsearch(card, item, left, middle - 1);
		else return 1;
	}

	return 0;

}