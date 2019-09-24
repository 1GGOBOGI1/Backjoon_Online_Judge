#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lca(int u, int v, int *depth, int *parent, bool *check, int *cost)
{
    int weight = 0;
    if (depth[u] < depth[v])
        swap(u, v);
    while (depth[u] != depth[v])
    {
        weight += cost[u];
        u = parent[u];
    }
    while (u != v)
    {
        weight = weight+ (cost[u] + cost[v]);
        u = parent[u];
        v = parent[v];
    }
    return weight;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> tree[N + 1];
    int depth[N + 1];
    int parent[N + 1];
    int cost[N + 1];
    bool check[N + 1];

    for (int i = 1; i < N; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
    }

    depth[1] = 0;
    check[1] = true;
    cost[1] = 0;

    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (pair<int, int> y : tree[x])
        {
            if (!check[y.first])
            {
                depth[y.first] = depth[x] + 1;
                check[y.first] = true;
                cost[y.first] = y.second;
                parent[y.first] = x;
                q.push(y.first);
            }
        }
    }

    int M;
    cin >> M;
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b, depth, parent, check, cost)<<"\n";
    }
}