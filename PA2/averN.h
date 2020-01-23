class averN{
private:
	int *data;
	int size;
	int select(int p, int r, int i);
	int partition(int p, int r);
public:
	averN(int *d, int s);
	int select(int i);
};

