#include "averN.h"
#include <algorithm>

averN::averN(int *d, int s){
	// Insert constructor here...
	size = s;
	data = new int[size];
	for (int i = 0; i < size;i++)
		data[i] = d[i];
	return;
}

int averN::select(int i){
	return select(0, size - 1, i);
}

int averN::select(int p, int r, int i){
	// Insert select function here...
	if (p == r)
		return data[p];

	int q = partition(p, r);
	int k = q - p;

	if(i==k)
		return data[q];
	else if(i<k)
		return select(p, q - 1, i);
	else
		return select(q + 1, r, i - k - 1);

	return 0;
}

int averN::partition(int p, int r){
	int i = p - 1;
	// Insert partition function here...
	int x = data[r];

	for (int j = p; j < r;j++)
	{
		if(data[j] <= x)
		{
			i = i + 1;
			std::swap(data[i], data[j]);
		}
	}
	std::swap(data[i + 1], data[r]);

	return i + 1;
}
