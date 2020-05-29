#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Road
{
    int x, y, p;
    Road(int _x, int _y, int _p) : x(_x), y(_y), p(_p){}
};

struct Compare
{
    bool operator()(Road a, Road b) {
        return a.p > b.p;
    }
};

bool compare(Road a, Road b) {
    return a.p > b.p;
}

struct UnionFind
{
    vector<int> parent, rank;

    UnionFind(int n): parent(n+1), rank(n+1,1) {
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int Find(int u)
    {
        if(u == parent[u])
            return u;

        return parent[u] = Find(parent[u]);
    }

    void Merge(int u, int v)
    {
        u = Find(u);
        v = Find(v);
        if(u == v)
            return;

        if(rank[u] > rank[v])
            swap(u, v);

        // always rank[u] < rank[v]

        parent[u] = v;

        if(rank[u] == rank[v])
            rank[v]++;

        return;
    }
};

long long solution(int N)
{
    long long price = 0;
    priority_queue<Road, vector<Road>, Compare> q;
    UnionFind uf(N);


    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1;j++)
        {
            int input;
            scanf("%d", &input);

            q.push(Road(i, j, input));
        }
    }

    while(!q.empty())
    {
        Road now = q.top();
        q.pop();

        if(uf.Find(now.x) == uf.Find(now.y))
            continue;

        uf.Merge(now.x, now.y);
        price += now.p;
    }

    return price;
}

int main()
{
    int N;
    scanf("%d", &N);

    printf("%lld", solution(N));
}