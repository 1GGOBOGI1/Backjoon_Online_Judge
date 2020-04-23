#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct jewel
{
    int weight, price;
};

struct JewelMaxHeap
{
    vector<jewel> heap;
    int count;

    JewelMaxHeap(int n) : heap(n + 1), count(0){};

    void push(jewel input)
    {
        heap[++count] = input;

        for (int i = count; i != 1 && heap[i].price > heap[i / 2].price; i = i / 2)
            swap(heap[i], heap[i / 2]);
    }

    jewel pop()
    {
        jewel front = heap[1];

        swap(heap[1], heap[count--]);

        for (int i = 1; i * 2 <= count;)
        {
            if (heap[i].price > heap[i * 2].price)
            {
                if (i * 2 + 1 <= count)
                {
                    if (heap[i].price > heap[i * 2 + 1].price)
                        break;
                }
                else
                {
                    break;
                }
            }

            if (i * 2 + 1 <= count && heap[i * 2].price < heap[i * 2 + 1].price)
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

    jewel top()
    {
        return heap[1];
    }

    bool empty()
    {
        if (count == 0)
            return true;
        return false;
    }
};

struct MinHeap
{
    vector<int> heap;
    int count;

    MinHeap(int n) : heap(n + 1), count(0) {}

    void push(int input)
    {
        heap[++count] = input;

        for (int i = count; i != 1 && heap[i] < heap[i / 2]; i = i / 2)
            swap(heap[i], heap[i / 2]);
    }

    int pop()
    {
        int front = heap[1];
        swap(heap[1], heap[count--]);

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
                {
                    break;
                }
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

    int top()
    {
        return heap[1];
    }
};

bool cmp(const jewel &a, const jewel &b)
{
    if (a.weight < b.weight)
        return true;
    return false;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    vector<jewel> shop(N + 1);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &shop[i].weight, &shop[i].price);

    sort(shop.begin(), shop.end(), cmp);

    MinHeap bag(K);
    for (int i = 1; i <= K; i++)
    {
        int input;
        scanf("%d", &input);
        bag.push(input);

    }

    long long ans = 0;
    JewelMaxHeap jeweles(N);

    for (int i = 1, j = 1; j <= K; j++)
    {
        int weightLimit = bag.pop();
        while (i <= N && shop[i].weight <= weightLimit)
            jeweles.push(shop[i++]);

        if (!jeweles.empty())
            ans += jeweles.pop().price;
    }

    printf("%lld", ans);
}