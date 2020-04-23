#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct GasStation
{
    int distance, amount;
};

struct MaxHeap
{
    vector<int> heap;
    int count;

    MaxHeap(int n) : heap(n+1,0), count(0) {}

    void push(int input)
    {
        heap[++count] = input;

        for (int i = count; i != 1 && heap[i] > heap[i/2]; i = i / 2)
            swap(heap[i], heap[i / 2]);
    }

    int pop()
    {
        int front = heap[1];
        swap(heap[1], heap[count--]);

        for (int i = 1; i * 2 <= count;)
        {
            if(heap[i] > heap[i*2])
            {
                if(i*2+1<=count)
                {
                    if(heap[i] > heap[i*2+1])
                        break;
                }
                else
                {
                    break;
                }
            }

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

    bool empty()
    {
        if(count == 0)
            return true;
        return false;
    }
};

bool cmp(const GasStation &a, const GasStation &b)
{
    if (a.distance < b.distance)
        return true;
    else if (a.distance == b.distance && a.amount > b.amount)
        return true;

    return false;
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<GasStation> gasStation;
    for (int i = 0; i < N; i++)
    {
        GasStation tmp;
        scanf("%d %d", &tmp.distance, &tmp.amount);
        gasStation.push_back(tmp);
    }
    sort(gasStation.begin(), gasStation.end(), cmp);

    int L, P;
    scanf("%d %d", &L, &P);

    long long movingDistance = P;
    int ans = 0;

    MaxHeap reacheableStation(N);
    for (int i = 0; movingDistance < L;)
    {
        while (i < N && gasStation[i].distance <= movingDistance)
            reacheableStation.push(gasStation[i++].amount);

        if(!reacheableStation.empty())
        {
            movingDistance += reacheableStation.pop();
            ans++;
        }
        else
        {
            break;
        }
        
    }

    movingDistance >= L ? printf("%d", ans) : printf("%d",-1);
}