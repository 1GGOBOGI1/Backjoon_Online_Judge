#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;

// V = 컴퓨터의 수, E = 연결할 수 있는 선의 수
int V, E;

struct cmp
{
    bool operator()(edge a, edge b)
    {
        return a.second > b.second;
    }
};

void prim(int start_vertex, vector<edge> *graph)
{
    bool visit[V + 1] = {false};
    visit[start_vertex] = true;

    priority_queue<edge, vector<edge>, cmp> q;

    for (int i = 0; i < graph[start_vertex].size(); i++)
    {
        q.push(edge(graph[start_vertex][i].first, graph[start_vertex][i].second));
    }

    long long int total_weight = 0;

    while (!q.empty())
    {
        edge x = q.top();
        q.pop();

        if (visit[x.first])
            continue;

        visit[x.first] = true;
        total_weight += x.second;

        for (int i = 0; i < graph[x.first].size(); i++)
        {
            q.push(edge(graph[x.first][i].first, graph[x.first][i].second));
        }
    }

    cout << total_weight;
}

int main()
{
    cin >> V >> E;

    vector<edge> graph[V + 1];

    for (int i = 0; i < E; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from].push_back(edge(to, weight));
        graph[to].push_back(edge(from, weight));
    }

    prim(1, graph);
}