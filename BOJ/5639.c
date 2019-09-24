#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct tree_node *tree_ptr;

struct tree_node {
	tree_ptr left_link;
	int data;
	tree_ptr right_link;
};

tree_ptr list = NULL;
void insert_BST(tree_ptr tree, int item);

int main(void) {
	int num;
	/*do {
		insert_BST(list, num);
		scanf("%d", &num);
	} while (num != EOF);*/
	scanf("%d", &num);
	while (num!="\n") {
		getchar();
		printf("hello\n");
		scanf("%d", &num);
		//insert_BST(list, num);
	}

	return 0;
}

void insert_BST(tree_ptr tree, int item) {
	tree_ptr node = (tree_ptr)malloc(sizeof(struct tree_node));
	node->data = item;
	node->left_link = NULL;
	node->right_link = NULL;

	tree_ptr temp, prev;
	if (tree == NULL) tree = node;
	else {
		temp = tree;
		prev = NULL;

		while (1) {
			prev = temp;

			if (item < prev->data) {
				temp = temp->left_link;
				if (temp == NULL) {
					prev->left_link = node;
					return;
				}
			}
			else if (item > prev->data) {
				temp = temp->right_link;
				if (temp == NULL) {
					prev->right_link = node;
					return;
				}
			}
		}
	}
}