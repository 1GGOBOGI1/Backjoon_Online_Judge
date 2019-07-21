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