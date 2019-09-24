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

void prim_with_priority_queue(int start_vertex, vector<edge> *graph)
{
    // 방문 여부를 저장하는 visit 배열
    bool visit[V + 1] = {false};

    // 시작 정점은 방문한 것임
    visit[start_vertex] = true;

    // edge 자료형으로 이루어진 priority queue
    // weight(x.second)값을 기준으로 정렬함
    priority_queue<edge, vector<edge>, cmp> q;

    // start_vertex에서 뻗은 모든 edge를 큐에 넣음
    for (int i = 0; i < graph[start_vertex].size(); i++)
    {
        q.push(graph[start_vertex][i]);
    }

    // prim에 의해 선택될 모든 edge의 weight의 합을 나타내는 total_weight
    long long int total_weight = 0;

    while (!q.empty())
    {
        edge x = q.top();
        q.pop();

        //이미 방문했던 정점이라면 skip
        if (visit[x.first])
            continue;

        visit[x.first] = true;
        total_weight += x.second;

        // 새롭게 방문한 정점에서 뻗은 모든 edge를 큐에 넣음
        for (int i = 0; i < graph[x.first].size(); i++)
        {
            q.push(graph[x.first][i]);
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

        //무방향 그래프이므로 양쪽으로 edge를 저장
        graph[from].push_back(edge(to, weight));
        graph[to].push_back(edge(from, weight));
    }

    prim_with_priority_queue(1, graph);
}