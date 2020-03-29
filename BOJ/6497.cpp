#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int makeGraph(vector<pair<int, int>> *g, int E)
{
    int totalCost = 0;
    for (int i = 0; i < E; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
        totalCost += z;
    }
    return totalCost;
}

int Prim(vector<pair<int, int>> *graph, int V, int start)
{
    bool check[V] = {false};
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    int edge = 0;
    int cost = 0;

    check[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
        q.push(graph[start][i]);

    while (!q.empty())
    {
        int now = q.top().first;
        int _cost = q.top().second;
        q.pop();

        if(check[now])
            continue;
        
        check[now] = true;
        cost += _cost;
        edge++;

        for (int i = 0; i < graph[now].size(); i++)
            q.push(graph[now][i]);
    }
    return cost;
}

int main()
{
    while (1)
    {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0)
            break;

        vector<pair<int, int>> graph[m];

        int totalCost = makeGraph(graph, n);
        int cost = Prim(graph, m, 0);
        cout << totalCost - cost << "\n";
    }
}