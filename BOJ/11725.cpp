#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph(vector<int> *graph, int E)
{
    while (E--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void BFS(vector<int> *graph, int V, int *parent)
{
    queue<int> q;
    bool check[V + 1] = {false};

    check[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (!check[next])
            {
                parent[next] = now;
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> graph[N + 1];
    int parent[N + 1];

    makeGraph(graph, N - 1);
    BFS(graph, N, parent);

    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";
}