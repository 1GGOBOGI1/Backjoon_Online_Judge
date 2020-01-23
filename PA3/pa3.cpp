#include <iostream>
#include "bst.h"
using namespace std;

int main(void){
	bst *tree = new bst();

	string *words = new string[5];
	int *p = new int[6];
	int *q = new int[6];

	p[0] = 0;
	q[0] = 1500;
	words[0] = "cat";
	p[1] = 500;
	q[1] = 500;
	words[1] = "dog";
	p[2] = 1000;
	q[2] = 1000;
	words[2] = "frog";
	p[3] = 1000;
	q[3] = 500;
	words[3] = "monkey";
	p[4] = 500;
	q[4] = 500;
	words[4] = "shark";
	p[5] = 1000;
	q[5] = 2000;

	tree->buildOptimalBST(words, p, q, 5);
	tree->printTree();
	delete p, q, words;
	delete tree;
	return 0;
}
