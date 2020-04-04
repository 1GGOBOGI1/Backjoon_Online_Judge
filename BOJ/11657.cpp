/*
// 2019-07-23
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#define INF 9999999
using namespace std;

typedef pair<int, int> edge;

int main()
{
    // N = 도시의 개수, M = 버스 노선의 개수
    int N, M;
    cin >> N >> M;

    vector<edge> graph[N + 1];

    for (int i = 0; i < M; i++)
    {
        int from;
        edge tmp;
        cin >> from >> tmp.first >> tmp.second;

        graph[from].push_back(tmp);
    }

    bool negative_cycle = false;

    // 시작점인 1을 제외하고 나머지는 INF로 초기화
    int d[N + 1];
    for (int i = 2; i < N + 1; i++)
        d[i] = INF;
    d[1] = 0;

    queue<int> q;

    int c[N + 1];
    int cnt[N + 1];

    q.push(1);
    c[1] = true;

    while (!q.empty())
    {
        int from = q.front();
        c[from] = false;
        q.pop();

        for (int i = 0; i < graph[from].size(); i++)
        {
            int to = graph[from][i].first;
            int cost = graph[from][i].second;

            if (d[to] > d[from] + cost)
            {
                d[to] = d[from] + cost;
                if (c[to] == false)
                {
                    q.push(to);
                    c[to] = true;
                    cnt[to] += 1;
                    if (cnt[to] >= N)
                    {
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 2; i <N+1; i++)
    {
        if (d[i] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << d[i] << endl;
        }
    }
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 9999999
using namespace std;

struct edge
{
    int u = -1;
    int v = -1;
    int c = MAX;
};

void makeGraph(vector<edge> &graph, int E)
{
    for (int i = 0; i < E; i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.c;
        graph.push_back(e);
    }
}

void BellmanFord(vector<edge> &graph, int V)
{
    int d[V + 1];

    for (int i = 0; i <= V; i++)
        d[i] = MAX;
    
    d[1] = 0;

    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            edge e = graph[j];
            if (d[e.u] != MAX && d[e.v] > d[e.u] + e.c)
            {
                if (i == V)
                {
                    cout << "-1\n";
                    return;
                }
                d[e.v] = d[e.u] + e.c;
            }
        }
    }

    for (int i = 2; i <= V; i++)
    {
        if (d[i] == MAX)
            cout << "-1\n";
        else
            cout << d[i] << "\n";
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<edge> edges(N + 1);
    makeGraph(edges, M);
    BellmanFord(edges, N);
}
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 9999999;
using namespace std;

struct edge
{
    int u = -1;
    int v = -1;
    int c = MAX;
};

void makeGraph(vector<edge> &edges, int E)
{
    for (int i = 0; i < E;i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.c;
        edges.push_back(e);
    }
}

void BellmanFord(vector<edge> &edges, int V, int start)
{
    int d[V + 1];

    for (int i = 0; i <= V;i++)
        d[i] = MAX;

    d[start] = 0;

    for (int i = 1; i <= V;i++)
    {
        for (int j = 0; j < edges.size();j++)
        {
            edge e = edges[j];
            if(d[e.u] != 9999999 && d[e.v] > d[e.u] + e.c)
            {
                if(i == V)
                {
                    cout << "-1\n";
                    return;
                }
                d[e.v] = d[e.u] + e.c;
            }
        }
    }

    for (int i = 1; i <= V;i++)
    {
        if(i == start)
            continue;
        if(d[i] == 9999999)
        {
            cout << "-1\n";
        }
        else
            cout << d[i] << "\n";
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<edge> edges;
    makeGraph(edges, M);
    BellmanFord(edges, N,1);
}