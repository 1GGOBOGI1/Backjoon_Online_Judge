// 2020-03-26
// prim algorithm
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph(vector<pair<int, int>> *g, int E)
{
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
}

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int Prim(vector<pair<int, int>> *g, int V, int start)
{
    int remainNode = V;
    int totalCost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    bool check[V + 1] = {false};

    check[start] = true;
    V--;
    for (int i = 0; i < g[start].size(); i++)
        q.push(g[start][i]);

    while (V != 0 && !q.empty())
    {
        int now = q.top().first;
        if (!check[now])
        {
            totalCost += q.top().second;
            check[now] = true;
            V--;

            for (int i = 0; i < g[now].size(); i++)
            {
                int next = g[now][i].first;
                q.push(g[now][i]);
            }
        }
        else
        {
            q.pop();
        }
    }

    return totalCost;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> graph[N + 1];

    makeGraph(graph, M);

    cout << Prim(graph, N, 1);
}
*/

// kruscal algorithm

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;

struct DisjointSet
{
    vector<int> parent, height;
    DisjointSet(int n) : parent(n + 1), height(n + 1, 1)
    {
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int a)
    {
        if (a == parent[a])
            return a;

        return parent[a] = find(parent[a]);
    }

    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (height[a] > height[b])
            swap(a, b);
        parent[a] = b;

        if (height[a] == height[b])
            height[a]++;
    }
};

struct cmp
{
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first > b.first;
    }
};

void makeGraph(priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> &g, int E)
{
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge e = make_pair(a, b);
        g.push(make_pair(c, e));
    }
}

int Kruscal(priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> g, int V)
{
    int currentEdge = 0;
    int totalCost = 0;
    DisjointSet disjointSet(V);

    while (currentEdge != V - 1)
    {
        int u = g.top().second.first;
        int v = g.top().second.second;

        if (disjointSet.find(u) != disjointSet.find(v))
        {
            disjointSet.merge(u, v);
            totalCost += g.top().first;
            currentEdge++;
        }
        g.pop();
    }
    return totalCost;
}

int main()
{
    int N, M;
    cin >> N >> M;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> graph;

    makeGraph(graph, M);
    cout << Kruscal(graph, N);
}