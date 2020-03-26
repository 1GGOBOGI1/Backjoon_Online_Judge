/*
// 2019-07-21

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    //n = 학생수, M = 키를 비교한 횟수
    int N, M;
    cin >> N >> M;

    //graph를 저장하기 위한 2차원 vector
    vector<vector<int>> graph(N + 1);
    //각 vertex의 indegree를 저장하는 배열
    int indegree[N + 1] = {0};

    //키를 비교한 학생 번호 A,B
    int A, B;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        //(학생 A가 학생 B의 앞에 서야 함) == (A는 B의 indegree를 하나 증가시킴)
        indegree[B]++;
        graph[A].push_back(B);
    }

    //위상정렬(topological sort)을 사용하기 위한 queue
    queue<int> q;

    //초기 그래프에서 indegree = 0인 vertex를 찾음
    for (int i = 1; i < N + 1; i++)
        if (indegree[i] == 0)
            q.push(i);

    //위상정렬
    for (int i = 1; i < N + 1; i++)
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        //x를 pop했다는 것은 x를 완료한 것이므로
        //x에서 나가는(x -> y) 화살표로 연결된 모든 y의 indegree를 하나 줄여줘야 함
        for (int j = 0; j < graph[x].size(); j++)
        {
            int y = graph[x][j];
            indegree[y]--;
            //이때 y의 indegree가 0이면 queue에 넣을 수 있음
            if (indegree[y] == 0)
                q.push(y);
        }
    }
}
*/

//2020-03-26

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph(vector<int> *graph, vector<int> &indegree, int E)
{
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;

        graph[A].push_back(B);
        indegree[B]++;
    }
}

void TopologicalSort(vector<int> *g, vector<int> &indegree, int N)
{
    queue<int> q;
    queue<int> answer;

    for (int i = 1; i <= N;i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int now = q.front();
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