#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct MaxHeap
{
    vector<int> heap;
    int count;

    MaxHeap() : heap(100001, 0), count(0) {}

    void push(int input)
    {
        heap[++count] = input;

        for (int i = count; i != 1 && heap[i] > heap[i / 2]; i = i / 2)
            swap(heap[i], heap[i / 2]);
    }

    int pop()
    {
        if (count == 0)
            return -1;

        int front = heap[1];

        swap(heap[1], heap[count]);
        heap[count--] = 0;

        for (int i = 1; i * 2 <= count;)
        {
            if(heap[i] > heap[i*2])
                if(i*2+1 <= count)
                {
                    if(heap[i] > heap[i*2+1])
                        break;
                }
                else
                    break;

            if(i*2+1 <= count && heap[i*2] < heap[i*2+1])
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

    int top()
    {
        return heap[1];
    }

    int size()
    {
        return count;
    }
};

struct MinHeap
{
    vector<int> heap;
    int count;

    MinHeap() : heap(100001, 0), count(0) {}

    void push(int input)
    {
        heap[++count] = input;

        for (int i = count; i != 1 && heap[i] < heap[i / 2]; i = i / 2)
            swap(heap[i], heap[i / 2]);
    }

    int pop()
    {
        if (count == 0)
            return -1;

        int front = heap[1];

        swap(heap[1], heap[count]);
        heap[count--] = 0;

        for (int i = 1; i * 2 <= count;)
        {
            if(heap[i] < heap[i*2])
                if(i*2+1 <= count)
                {
                    if(heap[i] < heap[i*2+1])
                        break;
                }
                else
                    break;

            if(i*2+1 <= count && heap[i*2] > heap[i*2+1])
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

    int top()
    {
        return heap[1];
    }

    int size()
    {
        return count;
    }
};

struct FindMiddle
{
    MaxHeap lessThenMiddle;
    MinHeap greaterThenMiddle;
    //priority_queue<int, vector<int>, less<int>> lessThenMiddle;
    //priority_queue<int, vector<int>, greater<int>> greaterThenMiddle;
    int count = 0;
    int middle = 0;

    int insert(int input)
    {
        if (count == 0)
        {
            middle = input;
            count++;
            lessThenMiddle.push(input);
            return middle;
        }

        if (middle >= input)
            lessThenMiddle.push(input);
        else
            greaterThenMiddle.push(input);

        int middleCount;
        if (++count % 2) // 총 홀수개
            middleCount = count / 2 + 1;
        else
            middleCount = count / 2;

        if (lessThenMiddle.size() > middleCount)
        {
            while (lessThenMiddle.size() != middleCount)
            {
                greaterThenMiddle.push(lessThenMiddle.pop());
            }
        }
        else
        {
            while (lessThenMiddle.size() != middleCount)
            {
                lessThenMiddle.push(greaterThenMiddle.pop());
            }
        }
        middle = lessThenMiddle.top();
        return middle;
    }
};

int main()
{
    int N;
    scanf("%d", &N);

    FindMiddle findMiddle;

    while (N--)
    {
        int input;
        scanf("%d", &input);
        printf("%d\n", findMiddle.insert(input));
    }
}