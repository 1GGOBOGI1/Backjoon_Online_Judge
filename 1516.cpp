#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    // N = 건물의 종류 수
    int N;
    cin >> N;

    // 1 ~ N까지의 정점을 가진 그래프를 나타내는 2차원 vector
    vector<vector<int>> graph(N + 1);

    // 각 정점의 indegree를 나타내는 배열
    int indegree[N + 1] = {0};

    // time[x] = 작업 x를 수행하는데 걸리는 시간
    int time[N + 1] = {0};

    // doneTime[x] = 작업 x를 완료하는데 걸리는 시간
    int doneTime[N + 1] = {0};

    //위상정렬 큐
    queue<int> q;

    for (int i = 1; i < N+1;i++)
    {
        cin >> time[i] >> indegree[i];

        if(indegree[i]==-1)
        {
            indegree[i] = 0;
            q.push(i);
            doneTime[i] = time[i];
        }
        else
        {
            int v = indegree[i];
            int deg = 0;

            do
            {
                graph[v].push_back(i);
                deg++;
                cin >> v;
            } while (v!=-1);

            indegree[i] = deg;
        }
        
        
    }

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size();i++)
        {
            int y = graph[x][i];

            indegree[y]--;

            if(doneTime[x]+time[y]>doneTime[y])
                doneTime[y] = doneTime[x] + time[y];

            if(indegree[y]==0)
                q.push(y);
        }
    }

    for (int i = 1; i < N + 1;i++)
        cout << doneTime[i] << "\n";
}