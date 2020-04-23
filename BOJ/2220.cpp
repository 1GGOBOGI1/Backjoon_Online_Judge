#include <iostream>
#include <vector>
using namespace std;

struct MaxHeap
{
    vector<int> heap;
    int count;

    MaxHeap(int n) : heap(n + 1, 0), count(0) {}

    void push(int input)
    {
        heap[++count] = input;
        if (count >= 2)
        {
            swap(heap[count - 1], heap[count]);

            for (int i = count - 1; i != 1 && heap[i] > heap[i / 2]; i = i / 2)
                swap(heap[i], heap[i / 2]);
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= count; i++)
            printf("%d ", heap[i]);
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    MaxHeap maxHeap(n);

    for (int i = 1; i <= n; i++)
        maxHeap.push(i);

    maxHeap.printHeap();
}