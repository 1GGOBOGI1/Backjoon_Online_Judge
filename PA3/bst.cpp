#include "bst.h"
#include <iostream>

bst::bst(){
	this->root = NULL;
}

void bst::buildOptimalBST(string *words, int *p, int *q, int n){
	
	// Insert source code here...
	int **e = new int*[n + 2];
	int **w = new int*[n + 2];
	this->rootValue = new int*[n + 2];

	int l, i, j, t, k;

	for (i = 0; i <= n + 1;i++)
	{
		e[i] = new int[n + 2];
		w[i] = new int[n + 2];
		rootValue[i] = new int[n + 2];
	}

	for (i = 1; i <= n + 1; i++)
	{
		w[i][i - 1] = q[i - 1];
		e[i][i - 1] = q[i - 1];
	}

	for (l = 1; l < n + 1; l++)
	{
		for (i = 1; i <= n - l + 1;i++)
		{
			j = i + l - 1;
			e[i][j] = 0x7FFFFFFF;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			for (k = i; k <= j;k++)
			{
				t = e[i][k - 1] + e[k + 1][j] + w[i][j];
				if(t<e[i][j])
				{
					e[i][j] = t;
					rootValue[i][j] = k;
				}
			}
		}
	}

	/*
	std::cout << "\nprint e array\n";
	for (i = 1; i <= n + 1;i++)
	{
		for (j = 0; j <= n;j++)
			std::cout << e[i][j] << " ";
		cout << "\n";
	}

	std::cout << "\n\nprint w array\n";
	for (i = 1; i <= n + 1; i++)
	{
		for (j = 0; j <= n; j++)
			std::cout << w[i][j] << " ";
		cout << "\n";
	}

	std::cout << "\n\nprint rootValue array\n";
	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
			std::cout << rootValue[i][j] << " ";
		cout << "\n";
	}
	*/
	root = this->connect(1, n);

	this->putItems(words);
	return;
}

void bst::putItems(string *words){
	// Insert source code here...
	int *d = new int;
	int *k = new int;
	*d = 0;
	*k = 0;
	inorder(words, this->root, k, d);

	return;
}

void bst::printTree(void){
	// Insert source code here...
	preorder(root, 0);
	return;
}

node* bst::connect(int i,int j){
	node *tmp = new node;

	if(i == j)
	{
		node *leftLeaf = new node;
		node *rightLeaf = new node;
		tmp->leftnode = leftLeaf;
		tmp->rightnode = rightLeaf;
	}
	else
	{
		int rootKey = this->rootValue[i][j];

		if(rootKey == i)
		{
			node *leftLeaf = new node;
			tmp->leftnode = leftLeaf;
			tmp->rightnode = this->connect(rootKey + 1, j);
		}
		else if(rootKey == j)
		{
			node *rightLeaf = new node;
			tmp->leftnode = this->connect(i, rootKey - 1);
			tmp->rightnode = rightLeaf;
		}
		else
		{
			tmp->leftnode = this->connect(i, rootKey - 1);
			tmp->rightnode = this->connect(rootKey + 1, j);
		}
	}

	return tmp;
}

void bst::preorder(node* n,int depth) {
	for (int i = 0; i < depth; i++)
		std::cout << '\t';
	std::cout << n->value << "\n";

	if(n->leftnode!=NULL)
		this->preorder(n->leftnode, depth + 1);

	if(n->rightnode!=NULL)
		this->preorder(n->rightnode, depth + 1);
}

void bst::inorder(string *words,node *n,int* k, int* d) {
	if(n->leftnode == NULL && n->rightnode == NULL)
	{
		n->value = "d" + std::to_string(*d);
		*d = *d + 1;
	}
	else
	{
		if(n->leftnode!=NULL)
		{
			this->inorder(words, n->leftnode, k, d);
		}
		n->value = words[*k];
		*k = *k + 1;
		if (n->rightnode != NULL)
		{
			this->inorder(words, n->rightnode, k, d);
		}
	}
}