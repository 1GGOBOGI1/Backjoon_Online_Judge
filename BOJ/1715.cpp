#include <iostream>
#include <vector>
using namespace std;

struct MinHeap
{
private:
    vector<int> heap;
    int count;

public:
    MinHeap(int n) : heap(n + 1, 0), count(0) {}

    void insert(int input)
    {
        heap[++count] = input;

        for (int i = count; i != 1 && heap[i] < heap[i / 2]; i = i / 2)
            swap(heap[i], heap[i / 2]);
    }

    int pop()
    {
        if (count == 0)
            return 0;

        int front = heap[1];
        swap(heap[1], heap[count]);
        heap[count--] = 0;

        for (int i = 1; i * 2 <= count;)
        {
            if (heap[i] < heap[i * 2])
            {
                if (i * 2 + 1 <= count)
                {
                    if (heap[i] < heap[i * 2 + 1])
                        break;
                }
                else
                    break;
            }

            if (i * 2 + 1 <= count && heap[i * 2] > heap[i * 2 + 1])
            {
                swap(heap[i], heap[i * 2 + 1]);
                i = i * 2 + 1;
            }
            else
            {
                swap(heap[i], heap[i * 2]);
                i = i * 2;
            }
        }

        return front;
    }

    int size()
    {
        return count;
    }
};

int main()
{
    int N;
    scanf("%d", &N);

    MinHeap minHeap(N);

    for (int i = 0; i < N; i++)
    {
        int input;
        scanf("%d", &input);
        minHeap.insert(input);
    }

    int cost = 0;
    while (minHeap.size() != 1)
    {
        int a = minHeap.pop();
        int b = minHeap.pop();
        cost += a + b;
        minHeap.insert(a+b);
    }

    printf("%d", cost);
}