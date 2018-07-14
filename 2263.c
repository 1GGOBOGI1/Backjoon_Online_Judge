#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node *tree_ptr;

struct tree_node {
	tree_ptr left_link;
	char item;
	tree_ptr right_link;
};
tree_ptr make_tree(int left, tree_ptr mid, int right);
void preorder(tree_ptr ptr);
tree_ptr tree = NULL;

int root_index = 0;
int num=0, tmp;
char inorder[100001], postorder[100001];

int main(void) {
	scanf("%d", &num);
	tmp = num;
	for (int i = 0; i < num;i++) {

		getchar();
		scanf("%c", &inorder[i]);
	}
	for (int i = 0; i < num;i++) {
		getchar();
		scanf("%c", &postorder[i]);
	}
	make_tree(0, &tree, num - 1);
	preorder(tree);
	return 0;
}

tree_ptr make_tree(int left,tree_ptr mid,int right) {
	int target = 0;
	if (tmp--) {
		for (; target < num;target++) {
			if (postorder[tmp] == inorder[target]) break;
		}

		tree_ptr node = (tree_ptr)malloc(sizeof(struct tree_node));
		printf("inorder[target]=%c\n", inorder[target]);
		node->item = inorder[target];
		node->left_link = NULL;
		node->right_link = NULL;

		if (tree == NULL)tree = node;

		if (left == right) {
			return node;
		}
		printf("right_link\n");
		node->right_link = make_tree(target + 1, &node, right);
		printf("left_link\n");
		node->left_link = make_tree(left, &node, target - 1);
	}
}

void preorder(tree_ptr ptr) {
	
	if (ptr) {
		printf("%c ", ptr->item);
		preorder(ptr->left_link);
		preorder(ptr->right_link);
	}
}