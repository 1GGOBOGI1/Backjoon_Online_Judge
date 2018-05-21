#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void printheap(int heap[], int root, int n);
void makeheap(int heap[], int root, int n);
void heapsort(int heap[], int n);

int main(void) {

	int size, heap[1000001] = { 0 };

	scanf("%d", &size);
	for (int i = 1; i <= size;i++)scanf("%d", &heap[i]);
	heapsort(heap, size);
	printheap(heap, 1, size);
	return 0;
}

void makeheap(int heap[], int root, int n) {
	int child, tmp;
	tmp = heap[root];
	child = 2 * root;

	while (child <= n) {
		if ((child < n) && (heap[child] < heap[child + 1]))child++;
		if (tmp > heap[child])break;
		else {
			heap[child / 2] = heap[child];
			child *= 2;
		}
	}
	heap[child / 2] = tmp;
}

void heapsort(int heap[], int n) {
	int i, tmp;
	for (i = n / 2;i > 0;i--) makeheap(heap, i, n);
	for (i = n - 1;i > 0;i--) {
		tmp = heap[1];
		heap[1] = heap[i + 1];
		heap[i + 1] = tmp;
		makeheap(heap, 1, i);
	}
}

void printheap(int heap[], int root, int n) {
	for (int i = root;i <= n;i++)printf("%d\n", heap[i]);
}