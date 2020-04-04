#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int u, v, c;
};

struct dij
{
    int distance = -1;
    int prevNode = -1;
    bool check = false;
};

struct cmp
{
    bool operator()(edge a, edge b)
    {
        return a.c > b.c;
    }
};

void makeGraph(vector<edge> *graph, int E)
{
    for (int i = 0; i < E; i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.c;
        graph[e.u].push_back(e);
    }
}

void Dijkstra(vector<edge> *graph, int V)
{
    int start, end;
    cin >> start >> end;
    priority_queue<edge, vector<edge>, cmp> q;

    vector<dij> arr(V + 1);

    arr[start].distance = 0;
    arr[start].check = true;

    for (int i = 0; i < graph[start].size(); i++)
        q.push(graph[start][i]);

    while(!q.empty())
    {
        edge e = q.top();
        q.pop();

        if(arr[e.v].check)
            continue;
        
        if(arr[e.v].distance < arr[e.u].distance + e.c)
        {
            arr[e.v].distance = arr[e.u].distance + e.c;
            arr[e.v].prevNode = e.u;
            arr[e.v].check = true;

            for (int i = 0; i < graph[e.v].size();i++)
                q.push(graph[e.v][i]);
        }
    }

    cout << arr[end].distance << "\n";
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<edge> graph[N + 1];

    makeGraph(graph, M);
    Dijkstra(graph, N);
}