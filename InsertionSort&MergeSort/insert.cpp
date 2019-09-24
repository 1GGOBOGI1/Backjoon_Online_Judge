#include <iostream>
#include "insert.h"
using namespace std;

InsertionSort::InsertionSort(int s, int *d)
{
	// Write constructor here...
	size = s;
	data = d;
	sort();
	showArray();
}

void InsertionSort::showArray(void)
{
	int i = 0;
	for (i = 0; i < size; i++)
		cout << *(data + i) << " ";
	cout << endl;
}

void InsertionSort::sort(void)
{
	// Write insertion sort source code here...
	for (int j = 1; j < size; j++)
	{
		int key = data[j];
		int i = j - 1;
		while (i >= 0 && data[i] > key)
		{
			data[i + 1] = data[i];
			i = i - 1;
		}
		data[i + 1] = key;
	}
}
