#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print_array(int num[], int n);
void quicksort(int num[], int left, int right);

int main(void){
	int num[4] = { 0 };

	scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);

	quicksort(num, 0,3);

	printf("%d", num[2] * num[0]);
}

void quicksort(int num[], int left, int right) {
	int pivot, i, j, tmp;

	if (left < right) {
		i = left;
		j = right+1;
		pivot = num[left];
		do {
			do { i++; } while (num[i] < pivot);
			do { j--; } while (num[j] > pivot);
			if (i < j) {
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		} while (i < j);
		tmp = num[left];
		num[left] = num[j];
		num[j] = tmp;

		quicksort(num, left, j - 1);
		quicksort(num, j + 1, right);
	}
}

void print_array(int num[], int n) {
	for (int i = 0; i < n;i++)printf("%d ", num[i]);
	printf("\n");
}