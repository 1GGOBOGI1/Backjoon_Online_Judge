#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct AbsoluteHeap
{
    vector<int> heap;
    int count;

    AbsoluteHeap(int n) : heap(n, 0), count(0) {}

    void insert(int input)
    {
        heap[++count] = input;

        for (int i = count; i != 1 && abs(heap[i]) <= abs(heap[i / 2]); i = i / 2)
        {
            if (abs(heap[i]) < abs(heap[i / 2]) || (abs(heap[i]) == abs(heap[i / 2]) && heap[i] < heap[i / 2]))
                swap(heap[i], heap[i / 2]);
        }
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
            if (abs(heap[i]) < abs(heap[i * 2]) || (abs(heap[i]) == abs(heap[i * 2]) && heap[i] < heap[i * 2]))
            {    
                if (i * 2 + 1 <= count)
                {
                    if ((abs(heap[i]) < abs(heap[i * 2 + 1]) || (abs(heap[i]) == abs(heap[i * 2 + 1]) && heap[i] < heap[i * 2 + 1])))
                        break;
                }
                else
                {
                    break;
                }
            }

            if(i*2+1 <= count && (abs(heap[i*2]) > abs(heap[i*2+1]) || (abs(heap[i*2]) == abs(heap[i*2+1]) && heap[i*2] > heap[i*2+1])))
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

    AbsoluteHeap absoluteHeap(N);

    while(N--)
    {
        int input;
        scanf("%d", &input);

        if(input == 0)
            printf("%d\n", absoluteHeap.pop());
        else
            absoluteHeap.insert(input);
    }
}