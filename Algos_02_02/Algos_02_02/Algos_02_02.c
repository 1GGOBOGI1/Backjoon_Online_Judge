#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int push(int x, int *y);
int pop(int *y);
int size(int *y);
int empty(int *y);
int front(int *y);
int back(int *y);

int *stack = { 0 }, Front = -1, Rear = -1;

int main(void) {
	int N = 0, num = 0, j = 0;
	char str[6], c = 0;

	scanf("%d", &N);
	stack = (int*)malloc(sizeof(int)*N);
	for (int i = 0;i < N;i++) {

		scanf("%s", str);

		switch (strlen(str)) {

		case 3:
			printf("%d\n", pop(stack));
			break;

		case 4:
			if (!(strcmp(str, "push"))) {
				scanf("%d\n", &num);
				push(num, stack);
			}
			else if(!strcmp(str, "size")) printf("%d\n", size(stack));
			else printf("%d\n", back(stack));
			break;

		case 5:
			if (!(strcmp(str, "empty"))) {
				printf("%d\n", empty(stack));
			}
			else printf("%d\n", front(stack));
			break;
		}
	}

	free(stack);

	return 0;
}


int push(int x, int *y) {
	Rear++;
	*(y + Rear) = x;
	return 0;
}

int pop(int *y) {
	int n;
	if (Rear == Front) return -1;
	else {
		Front++;
		n = *(y + Front);
		return n;
	}
}

int size(int *y) {
	return Rear - Front;
}

int empty(int *y) {
	if (Rear == Front) return 1;
	else return 0;
}

int front(int *y) {
	if (Rear == Front) return -1;
	else return *(y + Front + 1);
}

int back(int *y) {
	if (Rear == Front) return -1;
	else return *(y + Rear);
}