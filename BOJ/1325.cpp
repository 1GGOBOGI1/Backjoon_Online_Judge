#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int>> &graph, int startNode, int N)
{
    queue<int> q;
    vector<bool> check(N+1,false);

    q.push(startNode);
    check[startNode] = true;

    int cnt = 1;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int i = 0; i <graph[now].size(); i++)
            if(!check[graph[now][i]])
            {
                cnt++;
                check[graph[now][i]] = true;
                q.push(graph[now][i]);
            }
    }

    return cnt;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector<int>> graph(N+1, vector<int>(0));

    for(int i = 0; i < M; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);

        graph[end].push_back(start);
    }

    int max = 0;
    vector<int> answer;

    for(int i = 1; i <= N; i++)
    {
        int cnt = BFS(graph,i,N);
        if(max == cnt)
        {
            answer.push_back(i);
        }
        else if(max < cnt)
        {
            max = cnt;
            answer.clear();
            answer.push_back(i);
        }
    }

    for(int i = 0; i < answer.size(); i++)
        printf("%d ", answer[i]);
}