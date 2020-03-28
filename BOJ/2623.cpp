#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph(vector<int> *g, vector<int> &indegree, int M)
{
    for (int i = 0; i < M;i++)
    {
        int num;
        cin >> num;

        int u = -1;
        int v = -1;
        for (int j = 0; j < num;j++)
        {
            // u -> v
            cin >> v;
            if(u != -1)
            {
                g[u].push_back(v);
                indegree[v]++;
            }   
            u = v;
        }
    }
}

void TopologicalSort(int V, int M)
{
    vector<int> graph[V + 1];
    vector<int> indegree(V + 1, 0);

    makeGraph(graph, indegree, M);
    queue<int> q;
    queue<int> answer;

    for (int i = 1; i <= V;i++)
        if(indegree[i] == 0)
            q.push(i);


    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        answer.push(now);
        for (int i = 0; i < graph[now].size();i++)
        {
            int next = graph[now][i];
            if(--indegree[next] == 0)
                q.push(next);
        }
    }

    if(answer.size() == V)
    {
        while(!answer.empty())
        {
            cout << answer.front() << "\n";
            answer.pop();
        }
    }
    else
    {
        cout << 0;
    }
    
}

int main()
{
    int N, M;
    cin >> N >> M;
    TopologicalSort(N, M);
}