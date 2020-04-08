#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

void BFS(vector<int> *node, int *parent, int *depth, int V, int start)
{
    queue<int> q;
    bool check[V + 1] = {false};

    check[start] = true;
    parent[start] = 0;
    depth[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < node[now].size(); i++)
        {
            int next = node[now][i];
            if (!check[next])
            {
                parent[next] = now;
                depth[next] = depth[now] + 1;
                check[next] = true;
                q.push(next);
            }
        }
    }
}

void makeGraph(vector<int> *node, int *parent, int *depth, int V)
{
    int E = V - 1;
    while (E--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        node[u].push_back(v);
        node[v].push_back(u);
    }
    BFS(node, parent, depth, V, 1);
}

void makeLCA(int *parent, int *depth, vector<vector<int>> &LCA, int V)
{
    int log;
    for (log = 1; (1 << log) <= V; log++)
        ;

    for (int i = 0; i <= V; i++)
    {
        vector<int> tmp(log, 0);
        LCA[i] = tmp;
    }

    for (int i = 1; i <= V; i++)
        LCA[i][0] = parent[i];

    for (int j = 1; (1 << j) < V; j++)
        for (int i = 1; i <= V; i++)
            if (LCA[i][j - 1] != 0)
                LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
}

int findLCA(vector<vector<int>> &LCA, int *depth, int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    // depth[u] > depth[v]
    int log = 1;
    for (log = 1; (1 << log) <= depth[u]; log++)
    {
    }
    log--;

    for (int i = log; i >= 0; i--)
        if (depth[u] - (1 << i) >= depth[v])
            u = LCA[u][i];

    if (u == v)
        return u;
    else
    {
        for (int i = log; i >= 0; i--)
            if (LCA[u][i] != 0 && LCA[u][i] != LCA[v][i])
            {
                u = LCA[u][i];
                v = LCA[v][i];
            }
        return LCA[u][0];
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> node[N + 1];
    int parent[N + 1];
    int depth[N + 1];
    makeGraph(node, parent, depth, N);

    vector<vector<int>> LCA(N + 1);
    makeLCA(parent, depth, LCA, N);

    int M;
    scanf("%d", &M);
    while (M--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", findLCA(LCA, depth, u, v));
    }
}