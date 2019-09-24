#include <iostream>
#include <cmath>
#include "merge.h"
using namespace std;

MergeSort::MergeSort(int s, int *d)
{
	// Write constructor here...
	size = s;
	data = d;
	sort();
	showArray();
}

void MergeSort::showArray(void)
{
	int i = 0;
	for (i = 0; i < size; i++)
		cout << *(data + i) << " ";
	cout << endl;
}

void MergeSort::sort(void)
{
	mSort(0, size - 1);
}

void MergeSort::mSort(int p, int r)
{
	// Write merge sort source code here...
	if (p < r)
	{
		int q = floor((p + r) / 2);
		mSort(p, q);
		mSort(q + 1, r);
		merge(p, q, r);
	}
}

void MergeSort::merge(int p, int q, int r)
{
	// Write merge source code here...
	int n1 = q - p + 1, n2 = r - q;
	int L[n1 + 1], R[n2 + 1];

	int i = 0, j = 0;
	for (i = 0; i < n1 - 1; i++)
		L[i] = data[p + i];
	for (j = 0; j < n2 - 1; j++)
		R[j] = data[q + j + 1];

	L[n1] = 0xFFFFFFF;
	R[n2] = 0xFFFFFFF;

	i = 0;
	j = 0;
	while ((i < n1) || (j < n2))
	{
		if (L[i] < R[j])
		{
			A[i + j] = L[i];
			i++;
		}
		else
		{
			A[i + j] = R[j];
			j++;
		}
	}
}
