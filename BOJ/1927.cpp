#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct MinHeap // heap에 들어오는 범위가 1 ~ 2^31-1 인 경우
{
    vector<unsigned int> heap;
    int count;
    MinHeap(int n) : heap(n + 1, pow(2,31)), count(0) {}

    void insert(unsigned int input)
    {
        heap[++count] = input;

        for (int i = count; i != 1 && heap[i] < heap[i / 2]; i = i / 2)
            swap(heap[i], heap[i / 2]);
    }

    unsigned int pop()
    {
        if (count == 0)
            return 0;

        int front = heap[1];

        swap(heap[1], heap[count]);
        heap[count--] =  pow(2,31); 

        for (int i = 1; i * 2 <= count;)
        {
            if (heap[i] < heap[i * 2] && heap[i] < heap[i * 2 + 1])
            {
                break;
            }
            else if (heap[i * 2] > heap[i * 2 + 1])
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

    MinHeap minHeap(N);

    while (N--)
    {
        unsigned int input;
        scanf("%u", &input);

        if (input == 0)
            printf("%u\n", minHeap.pop());
        else
            minHeap.insert(input);
    }
}