#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node *tree_ptr;

struct tree_node {
	tree_ptr left_link;
	char item;
	tree_ptr right_link;
};

tree_ptr tree = NULL;

void make_node();
void postorder(tree_ptr ptr);
void inorder(tree_ptr ptr);
void preorder(tree_ptr ptr);


int main(void){
	make_node();
	preorder(tree);
	printf("\n");
	inorder(tree);
	printf("\n");
	postorder(tree);
	return 0;
}

void make_node() {
	int num;
	char items[3];
	tree_ptr tmp = tree;
	tree_ptr address[26] = { NULL };

	scanf("%d", &num);
	for (int i = 0; i < num;i++) {
		getchar();
		scanf("%c %c %c", &items[0], &items[1], &items[2]);
		if (i == 0) {
			tree_ptr node = (tree_ptr)malloc(sizeof(struct tree_node));
			address[items[0] - 65] = node;
			node->item = items[0];
			node->left_link = NULL;
			node->right_link = NULL;
			tree = node;
		}
		if (items[1] != '.') {
			tree_ptr left_node = (tree_ptr)malloc(sizeof(struct tree_node));
			address[items[1] - 65] = left_node;
			left_node->item = items[1];
			left_node->left_link = NULL;
			left_node->right_link = NULL;
			address[items[0] - 65]->left_link = left_node;
		}
		if (items[2] != '.') {
			tree_ptr right_node = (tree_ptr)malloc(sizeof(struct tree_node));
			address[items[2] - 65] = right_node;
			right_node->item = items[2];
			right_node->left_link = NULL;
			right_node->right_link = NULL;
			address[items[0] - 65]->right_link = right_node;
		}
	}
}

void postorder(tree_ptr ptr) {
	if (ptr) {
		postorder(ptr->left_link);
		postorder(ptr->right_link);
		printf("%c", ptr->item);
	}
}

void inorder(tree_ptr ptr) {
	if (ptr) {
		inorder(ptr->left_link);
		printf("%c", ptr->item);
		inorder(ptr->right_link);
	}
}

void preorder(tree_ptr ptr) {
	if (ptr) {
		printf("%c", ptr->item);
		preorder(ptr->left_link);
		preorder(ptr->right_link);
	}
}