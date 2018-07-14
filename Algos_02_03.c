#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check(char *x);

int main(void) {
	int num;
	char str[50];
	scanf("%d", &num);
	for (int i = 0;i < num;i++) {
		scanf("%s", str);
		if (check(str) == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

int check(char *x) {
	int i = 0, j = -1;

	char save[50];

	while (*(x + i) != NULL) {
		if (*(x + i) == '(') {
			j++;
			*(save + j) = "(";
			i++;
		}
		else {
			if (j == -1) return 0;
			j--, i++;
		}
	}

	if (j == -1) return 1;
	else return 0;

}