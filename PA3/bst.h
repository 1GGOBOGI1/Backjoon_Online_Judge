#include <iostream>
#include "node.h"
using namespace std;

class bst{
private:
	node *root;
	void putItems(string *words);
	int **rootValue;
	node *connect(int i, int j);
	void preorder(node *n, int depth);
	void inorder(string *words, node *n, int* k, int* d);

public:
	bst();
	void buildOptimalBST(string* words, int *p, int *q, int n);
	void printTree(void);
};
