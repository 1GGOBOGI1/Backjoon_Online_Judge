#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
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
        scanf("%d %d %d", &a, &b, &c);
        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }
    BFS(node, V, parent, depth, 1);
}

void makeLCA(vector<vector<int>> &LCA, vector<vector<int>> &maxDistance, vector<vector<int>> &minDistance, int V, int (*parent)[2], int *depth)
{
    int log;
    for (log = 1; (1 << log) <= V; log++)
        ;
    for (int i = 1; i <= V; i++)
    {
        vector<int> tmp1(log);
        vector<int> tmp2(log);
        vector<int> tmp3(log);
        LCA[i] = tmp1;
        maxDistance[i] = tmp2;
        minDistance[i] = tmp3;
    }

    for (int i = 1; i <= V; i++)
    {
        LCA[i][0] = parent[i][0];
        maxDistance[i][0] = parent[i][1];
        minDistance[i][0] = parent[i][1];
    }

    for (int j = 1; (1 << j) < V; j++)
        for (int i = 1; i <= V; i++)
            if (LCA[i][j - 1] != 0)
            {
                LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];

                maxDistance[i][j] = max(maxDistance[i][j - 1], maxDistance[LCA[i][j - 1]][j - 1]);
                minDistance[i][j] = min(minDistance[i][j - 1], minDistance[LCA[i][j - 1]][j - 1]);
            }
}

void findLCA(vector<vector<int>> &LCA, vector<vector<int>> &maxDistance, vector<vector<int>> &minDistance, int *depth, int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    // depth[u] > depth[v]
    int log = 1;
    for (log = 1; (1 << log) <= depth[u]; log++)
        ;
    log--;

    int max_distance = -1;
    int min_distance = 1000000;

    for (int i = log; i >= 0; i--)
        if (depth[u] - (1 << i) >= depth[v])
        {
            if (max_distance < maxDistance[u][i])
                max_distance = maxDistance[u][i];
            if (min_distance > minDistance[u][i])
                min_distance = minDistance[u][i];
            u = LCA[u][i];
        }

    if (u == v)
    {
        printf("%d %d\n", min_distance, max_distance);
    }
    else
    {
        for (int i = log; i >= 0; i--)
            if (LCA[u][i] != 0 && LCA[u][i] != LCA[v][i])
            {
                if (max_distance < max(maxDistance[u][i], maxDistance[v][i]))
                    max_distance = max(maxDistance[u][i], maxDistance[v][i]);
                if (min_distance > min(minDistance[u][i], minDistance[v][i]))
                    min_distance = min(minDistance[u][i], minDistance[v][i]);
                u = LCA[u][i];
                v = LCA[v][i];
            }

        if (max_distance < max(maxDistance[u][0], maxDistance[v][0]))
            max_distance = max(maxDistance[u][0], maxDistance[v][0]);
        if (min_distance > min(minDistance[u][0], minDistance[v][0]))
            min_distance = min(minDistance[u][0], minDistance[v][0]);

        printf("%d %d\n", min_distance, max_distance);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<pair<int, int>> node[N + 1];
    // parent[i][0] = parent node 번호 parent[i][1] = parent까지 distance
    int parent[N + 1][2] = {0};
    int depth[N + 1] = {0};
    makeGraph(node, N, parent, depth);

    vector<vector<int>> LCA(N + 1);
    vector<vector<int>> maxDistance(N + 1);
    vector<vector<int>> minDistance(N + 1);

    makeLCA(LCA, maxDistance, minDistance, N, parent, depth);

    int M;
    scanf("%d", &M);
    while (M--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        findLCA(LCA, maxDistance, minDistance, depth, u, v);
    }
}