#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> child(N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &child[i]);
    }

    priority_queue<int,vector<int>,less<int>> pq;
    int ans = 0;

    for(int i = 1; i < N; i++)
    {
        int price = child[i] - child[i-1];

        ans += price;

        pq.push(price);
    }
    K--;

    while(K--)
    {
        ans -= pq.top();
        pq.pop();
    }

    printf("%d", ans);
}