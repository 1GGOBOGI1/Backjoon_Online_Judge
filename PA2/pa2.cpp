#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "averN.h"
#include "second.h"
#include "time.h"

using namespace std;

int *genArray(int n);

int main(int argc, char* argv[]){
	int n = 0, i = 0;
	int *data = 0;
	averN* aN = 0;
	second* s = 0;

	if(argc < 3){
		cout<<"Usage: ./foo [n value] [i value]"<<endl;
		return 0;
	}
	n = atoi(argv[1]);
	i = atoi(argv[2]);
	if(i>=n){
		cout<<"n should be larger than i"<<endl;
		return 0;
	}
	data = genArray(n);

	aN = new averN(data, n);
	s = new second(data, n);
	delete data;
	cout<<aN->select(i)<<endl;
	cout<<s->getSecond()<<endl;
	delete aN, s;
	return 0;
}

int *genArray(int n){
	int *data = 0;
	// Insert source code for generating array here...
	srand((unsigned int)time(0));

	data = new int[n];
	data[0] = rand() % 20;
	for (int i = 1; i < n; i++)
		data[i] = data[i - 1] + (rand() % 20) + 1;

	int index = 0;

	for (int i = 0;i<n;i++)
	{
		index = rand() % (n - i) + (i);
		swap(data[i], data[index]);
	}

	return data;
}
