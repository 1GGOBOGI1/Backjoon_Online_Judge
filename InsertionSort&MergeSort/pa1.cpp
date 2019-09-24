#include <iostream>
#include <chrono>
#include <iomanip>
#include "insert.h"
#include "merge.h"
using namespace std;
using namespace chrono;

int *readFile(char *filename, int *size);

int main(int argc, char *argv[])
{
	int item = 0, n = 0, i = 0;
	int *data = 0;

	InsertionSort *is = 0;
	MergeSort *ms = 0;

	if (argc < 2)
	{
		cout << "No input file!" << endl;
		return 0;
	}
	data = readFile(argv[1], &n);

	//Write source code for measuring operation times of Insertion Sort and Merge Sort here...

	is = new InsertionSort(n, data);
	ms = new MergeSort(n, data);

	chrono::system_clock::time_point is_start = chrono::system_clock::now();
	is->sort();
	chrono::system_clock::time_point is_end = chrono::system_clock::now();

	chrono::system_clock::time_point ms_start = chrono::system_clock::now();
	ms->sort();
	chrono::system_clock::time_point ms_end = chrono::system_clock::now();

	chrono::nanoseconds is_runTime = is_start - is_end;
	chrono::nanoseconds ms_runTime = ms_start - ms_end;

	cout << setw(15) << "Number of items:" << n << endl
		 << setw(15) << "Insertion sort:" << is_runTime << setw(2) << "ns" << endl
		 << setw(15) << "Merge sort:" << ms_runTime << setw(2) << "ns" << endl;

	delete data;
	return 0;
}
