#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int u, v, weight;
    bool operator<(const edge &other) const
    {
        return weight > other.weight;
    }
};

struct OptimizedDisjointSet
{
    vector<int> parent, rank;

    OptimizedDisjointSet(int n) : parent(n + 1), rank(n + 1, 1)
    {
        for (int i = 1; i < n + 1; i++)
            parent[i] = i;
    }

    int find(int v)
    {
        if (v == parent[v])
            return v;

        return parent[v] = find(parent[v]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;

        if (rank[u] == rank[v])
            rank[v]++;
    }
};

void kruskal(priority_queue<edge> q, int N)
{
    OptimizedDisjointSet MST(N);

    long long int total_weight = 0;

    while (!q.empty())
    {
        edge x = q.top();
        q.pop();

        if (MST.find(x.u) != MST.find(x.v))
        {
            MST.merge(x.u, x.v);
            total_weight += x.weight;
        }
    }

    cout << total_weight;
}

int main()
{
    // N = 컴퓨터의 수, M = 연결할 수 있는 선의 수
    int V, E;
    cin >> V >> E;

    priority_queue<edge> q;

    for (int i = 0; i < E; i++)
    {
        edge tmp;
        cin >> tmp.u >> tmp.v >> tmp.weight;

        q.push(tmp);
    }

    kruskal(q, V);
}
