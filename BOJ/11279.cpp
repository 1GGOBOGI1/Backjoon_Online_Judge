#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct MaxHeap 
{
    vector<unsigned int> heap;
    int count;
    MaxHeap(int n) : heap(n + 1, 0), count(0) {}

    void insert(unsigned int input)
    {
        heap[++count] = input;

        for (int i = count; i != 1 && heap[i] > heap[i / 2]; i = i / 2)
            swap(heap[i], heap[i / 2]);
    }

    unsigned int pop()
    {
        if (count == 0)
            return 0;

        int front = heap[1];

        swap(heap[1], heap[count]);
        heap[count--] =  0; 

        for (int i = 1; i * 2 <= count;)
        {
            if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1])
            {
                break;
            }
            else if (heap[i * 2] < heap[i * 2 + 1])
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
};

int main()
{
    int N;
    scanf("%d", &N);

    MaxHeap MaxHeap(N);

    while (N--)
    {
        unsigned int input;
        scanf("%u", &input);

        if (input == 0)
            printf("%u\n", MaxHeap.pop());
        else
            MaxHeap.insert(input);
    }
}