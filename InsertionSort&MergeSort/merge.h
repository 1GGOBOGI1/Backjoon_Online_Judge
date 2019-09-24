class MergeSort{
private:
	int size;
	int* data;

	void mSort(int p, int r);
	void merge(int p, int q, int r);
public:
	MergeSort(int s, int* d);
	void showArray(void);
	void sort(void);
};

