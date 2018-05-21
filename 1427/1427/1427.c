#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void mergesort(int num[], int left, int right);
void merge(int num[], int left, int mid, int right);
void print_array(int num[], int n);

int same[10] = { 0 }, list[10] = { 0 };

int main(void) {
	int number = 0, size = 0, num[10] = { 0 };
	scanf("%d", &number);
	for (int i = 0;number!=0;i++) {
		if (same[number % 10] == 1) {
			list[number % 10]++;
			number = number / 10;
		}
		else {
			same[number % 10] = 1;
			list[number % 10] = 1;
			num[size] = number % 10;
			number = number / 10;
			size++;
		}

	}
	mergesort(num, 0, size - 1);
	print_array(num, size);
}

void mergesort(int num[], int left, int right) {
	int mid;
	
	if (right > left) {
		mid = (right + left) / 2;
		mergesort(num, left, mid);
		mergesort(num, mid + 1, right);
		merge(num, left, mid + 1, right);
	}
}

void merge(int num[], int left, int mid, int right) {
	int i, left_end, num_items, tmp_pos;
	int tmp[100];
	left_end = mid - 1;
	tmp_pos = left;
	num_items = right - left + 1;
	
	while ((left <= left_end) && (mid <= right)) {
		if (num[left] >= num[mid]) {
			tmp[tmp_pos] = num[left];
			tmp_pos = tmp_pos + 1;
			left = left + 1;
		}
		else {
			tmp[tmp_pos] = num[mid];
			tmp_pos++;
			mid++;
		}
	}

	while (left <= left_end) {
		tmp[tmp_pos] = num[left];
		left++;
		tmp_pos++;
	}

	while (mid <= right) {
		tmp[tmp_pos] = num[mid];
		mid++;
		tmp_pos++;
	}

	for (i = 0;i < num_items;i++) {
		num[right] = tmp[right];
		right--;
	}
}

void print_array(int num[], int n) {
	for (int i = 0; i < n;i++) {
		for (int j = 0;j < list[num[i]];j++) printf("%d", num[i]);
	}
	printf("\n");
}

