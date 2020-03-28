#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;

struct cmp
{
    bool operator()(pair<int, edge> a, pair<int, edge> b)
    {
        return a.first > b.first;
    }
};

struct DisjointSet
{
    vector<int> parent, height;
    DisjointSet(int n) : parent(n + 1), height(n + 1, 1)
    {
        for (int i = 1; i <= n; i++)
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

        if (height[u] > height[v])
            swap(u, v);
        parent[u] = v;

        if (height[u] == height[v])
            height[v]++;
    }
};

void makeGraph(priority_queue<pair<int, edge>, vector<pair<int, edge>>, cmp> &roads, int E)
{
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        roads.push(make_pair(c, make_pair(a, b)));
    }
}

int Kruscal(priority_queue<pair<int, edge>, vector<pair<int, edge>>, cmp> &roads, int V)
{
    DisjointSet disjointSet(V);
    int village = V;
    int cost = 0;

    while(village > 2)
    {
        int u = roads.top().second.first;
        int v = roads.top().second.second;

        if(disjointSet.find(u) != disjointSet.find(v))
        {
            disjointSet.merge(u, v);
            cost += roads.top().first;
            village--;
        }
        roads.pop();
    }

    return cost;
}

int main()
{
    int N, M;
    cin >> N >> M;

    priority_queue<pair<int, edge>, vector<pair<int, edge>>, cmp> roads;

    makeGraph(roads, M);
    cout << Kruscal(roads, N);
}