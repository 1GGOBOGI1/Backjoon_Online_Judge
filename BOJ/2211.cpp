#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct network
{
    int u, v, c;
};

struct cmp
{
    bool operator()(network a, network b)
    {
        return a.c > b.c;
    }
};

struct DisjointSet
{
    vector<int> parent, height;

    DisjointSet(int n) : parent(n + 1), height(n + 1)
    {
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (height[u] > height[v])
            swap(u, v);
        parent[u] = v;

        if (height[v] == height[u])
            height[v]++;
    }
};

void makeGraph(priority_queue<network, vector<network>, cmp> &q, int M)
{
    for (int i = 0; i < M; i++)
    {
        network n;
        cin >> n.u >> n.v >> n.c;

        q.push(n);
    }
}

void Kruscal(priority_queue<network, vector<network>, cmp> &q, int V)
{
    DisjointSet set(V);
    queue<pair<int,int>> answer;

    while (!q.empty())
    {
        int u = q.top().u;
        int v = q.top().v;
        int c = q.top().c;
        q.pop();

        if(set.find(u) == set.find(v))
            continue;

        set.merge(u, v);
        answer.push(make_pair(u, v));
    }

    cout << answer.size() << "\n";

    while(!answer.empty())
    {
        cout << answer.front().first << " " << answer.front().second << "\n";
        answer.pop();
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    priority_queue<network, vector<network>, cmp> q;

    makeGraph(q, M);
    Kruscal(q, N);
}