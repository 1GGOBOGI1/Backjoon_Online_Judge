#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main(void) {

	int num, result = 0;
	scanf("%d", &num);

	for (int i = 0; i < num;i++) {
		char str[100] = { NULL }, prev[100] = { NULL };
		int j = 0,k=0, check = 1;;

		scanf("%s", str);

		prev[0] = str[0];

		while (str[j]) {
			
			if (str[j] == prev[k]);
			else {
				for (int s = 0; s <= k;s++) {
					if (prev[s] == str[j]) {
						check = 0;
						break;
					}
				}
				if (check) prev[++k] = str[j];
			}
			j++;
		}
		if (check) result++;
	}
	printf("%d", result);
	return 0;
}