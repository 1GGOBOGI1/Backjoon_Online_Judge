#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<pair<int, int>> *node, int V, int (*parent)[2], int *depth, int start)
{
    queue<int> q;
    bool check[V + 1] = {false};

    parent[start][0] = 0;
    parent[start][1] = 0;
    depth[start] = 0;
    check[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < node[now].size(); i++)
        {
            int next = node[now][i].first;
            if (!check[next])
            {
                parent[next][0] = now;
                parent[next][1] = node[now][i].second;
                depth[next] = depth[now] + 1;
                check[next] = true;
                q.push(next);
            }
        }
    }
}

void makeGraph(vector<pair<int, int>> *node, int V, int (*parent)[2], int *depth)
{
    int E = V - 1;
    while (E--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }
    BFS(node, V, parent, depth, 1);
}

void makeLCA(vector<vector<int>> &LCA, int V, int (*parent)[2], int *depth)
{
    int log;
    for (log = 1; (1 << log) <= V; log++)
        ;
    for (int i = 1; i <= V; i++)
    {
        vector<int> tmp(log);
        LCA[i] = tmp;
    }

    for (int i = 1; i <= V; i++)
        LCA[i][0] = parent[i][0];

    for (int j = 1; (1 << j) < V; j++)
        for (int i = 1; i <= V; i++)
            if (LCA[i][j - 1] != 0)
                LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
}

void findLCA(vector<vector<int>> &LCA, int *depth, int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    // depth[u] > depth[v]

    int log = 1;
    for (log = 1; (1 << log) <= depth[u]; log++)
        ;
    log--;

    for (int i = log; i >= 0; i--)
        if(depth[u] - (1 << i) >= depth[v])
            u = LCA[u][i];
        
    if(u == v)
        return u;
    else
    {
        
    }
    
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> node[N + 1];
    int parent[N + 1][2] = {0};
    int depth[N + 1] = {0};
    makeGraph(node, N, parent, depth);

    vector<vector<int>> LCA(N + 1);
}