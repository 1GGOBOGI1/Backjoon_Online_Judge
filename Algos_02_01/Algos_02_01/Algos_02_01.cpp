#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int push(int x, int *y);
int pop(int *y);
int size(int *y);
int empty(int *y);
int top(int *y);

int *stack = { 0 }, Top = -1;


int main(void) {
	int N = 0, num = 0, j = 0;
	char str[6], c = 0;

	scanf("%d", &N);
	stack = (int*)malloc(sizeof(int)*N);
	for (int i = 0;i < N;i++) {
		scanf("%s", str);
		switch (strlen(str)) {
		case 3:
			if (!(strcmp(str, "pop"))) printf("%d\n", pop(stack));
			else printf("%d\n", top(stack));
			break;
		case 4:
			if (!(strcmp(str, "push"))) {
				scanf("%d\n", &num);
				push(num, stack);
			}
			else printf("%d\n", size(stack));
			break;
		case 5:
			printf("%d\n", empty(stack));
			break;
		}


	}

	free(stack);

	return 0;
}


int push(int x, int *y) {
	Top++;
	*(y + Top) = x;
	return 0;
}

int pop(int *y) {
	int n;
	if (Top < 0) return -1;
	else {
		n = *(y + Top);
		Top--;
		return n;
	}
}

int size(int *y) {
	return Top + 1;
}

int empty(int *y) {
	if (Top < 0) return 1;
	else return 0;
}

int top(int *y) {
	if (Top < 0) return -1;
	else return *(y + Top);
}
