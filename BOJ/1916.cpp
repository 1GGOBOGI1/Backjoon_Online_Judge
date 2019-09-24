#include <iostream>
#include <vector>
#include <queue>
#define INF 999999
using namespace std;

int main()
{
    // N = 도시 개수, M = 버스의 개수
    int N, M;
    cin >> N >> M;

    //fist = 도착 정점, second = cost
    vector<pair<int, int>> graph[N + 1];

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        //무방향 그래프
        graph[from].push_back(make_pair(to, cost));
    }

    int start, end;
    cin >> start >> end;

    int d[N + 1];
    bool c[N + 1];

    for (int i = 1; i < N + 1; i++)
    {
        d[i] = INF;
        c[i] = false;
    }

    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    //minheap queue. first = cost, second = vertex
    q.push(make_pair(0, start));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (!c[x])
        {
            c[x] = true;
            for (int i = 0; i < graph[x].size(); i++)
            {
                int y = graph[x][i].first;
                if (d[y] > d[x] + graph[x][i].second)
                {
                    d[y] = d[x] + graph[x][i].second;
                    q.push(make_pair(d[y], y));
                }
            }
        }
    }
    cout << d[end] << endl;
}