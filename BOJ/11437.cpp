#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> *node, int V, int *level, int *parent, int start)
{
    queue<int> q;
    bool check[V + 1] = {false};

    level[start] = 0;
    parent[start] = -1;
    check[start] = true;
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
                level[next] = level[now] + 1;
                parent[next] = now;
                check[next] = true;
                q.push(next);
            }
        }
    }
}

void makeGraph(vector<int> *node, int *level, int *parent, int V)
{
    int E = V - 1;
    while (E--)
    {
        int u, v;
        cin >> u >> v;

        node[u].push_back(v);
        node[v].push_back(u);
    }

    BFS(node, V, level, parent, 1);
}

int LCA(vector<int> *node, int *level, int *parent, int u, int v)
{
    if (u == v)
        return u;

    if (level[u] == level[v])
    {
        u = parent[u];
        v = parent[v];
    }
    else if (level[u] > level[v])
    {
        u = parent[u];
    }
    else if (level[u] < level[v])
    {
        v = parent[v];
    }

    if (u != -1 && v != -1)
        return LCA(node, level, parent, u, v);
    else
        return -1;
}

int main()
{
    int N;
    cin >> N;

    vector<int> node[N + 1];
    int level[N + 1] = {0};
    int parent[N + 1] = {0};
    makeGraph(node, level, parent, N);

    int M;
    cin >> M;

    while (M--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(node, level, parent, u, v) << "\n";
    }
}