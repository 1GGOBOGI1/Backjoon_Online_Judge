/*
// 2019-07-21
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    // N = 문제의 개수, M = 주어지는 선후관계 개수
    int N, M;
    cin >> N >> M;

    // 1~N의 정점을 가진 그래프를 표현하기 위한 2차원 vector
    vector<vector<int>> graph(N + 1);
    // 각 정점의 indegree를 저장하는 배열
    int indegree[N + 1] = {0};

    // A, B = 문제 번호
    int A, B;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        // A번 문제는 B번 문제보다 먼저 풀어야 함
        indegree[B]++;
        graph[A].push_back(B);
    }

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i < N + 1; i++)
        if (indegree[i] == 0)
            q.push(i);

    for (int i = 1; i < N + 1; i++)
    {
        int x = q.top();
        q.pop();
        cout << x << " ";

        for (int j = 0; j < graph[x].size(); j++)
        {
            int y = graph[x][j];
            indegree[y]--;
            if (indegree[y] == 0)
                q.push(y);
        }
    }
}
*/
// 2020-03-26

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph(vector<int> *g, vector<int> &indegree, int E)
{
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;

        g[A].push_back(B);
        indegree[B]++;
    }
}

void TopologicalSort(vector<int> *g, vector<int> &indegree, int V)
{
    priority_queue<int, vector<int>,greater<int>> q;
    queue<int> answer;

    for (int i = 1; i <= V;i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int now = q.top();
        q.pop();
        answer.push(now);

        for (int i = 0; i < g[now].size();i++)
        {
            int next = g[now][i];
            indegree[next]--;
            if(indegree[next] == 0)
                q.push(next);
        }
    }

    while(!answer.empty())
    {
        cout << answer.front() << " ";
        answer.pop();
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> graph[N + 1];
    vector<int> indegree(N + 1, 0);

    makeGraph(graph, indegree, M);
    TopologicalSort(graph, indegree, N);
}