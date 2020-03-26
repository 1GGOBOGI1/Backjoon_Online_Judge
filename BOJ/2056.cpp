/*
// 2019-07-21
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    // N = 작업 개수
    int N;
    cin >> N;

    // 1 ~ N의 정점을 가진 graph를 나타내는 2차원 vector
    vector<vector<int>> graph(N + 1);

    // 각 정점의 indegree를 나타내는 배열
    int indegree[N + 1] = {0};

    // 각 작업의 소요 시간을 나타내는 배열
    int time[N + 1] = {0};

    // doneTime[x] = 작업 x를 완료하기 위한 최소 시간
    int doneTime[N + 1] = {0};


    for (int i = 1; i < N + 1;i++)
    {
        cin >> time[i] >> indegree[i];

        for (int j = 0; j < indegree[i];j++)
        {
            int v;
            cin >> v;
            // 작업 i를 하기 전에 작업 v를 먼저 실행해야 함
            graph[v].push_back(i);
        }
    }

    // 실행 가능한 작업 큐
    queue<int> q;

    // 초기 graph에서 indegree == 0인 작업을 q에 넣음
    for (int i = 1; i < N + 1;i++)
        if(indegree[i]==0)
        {
            q.push(i);
            // 선행작업이 없는 작업들의 doneTime은 자신의 작업 소요 시간과 같음
            doneTime[i] = time[i];
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

    // 완료시간이 가장 큰 것이 정답임
    // 이때, 마지막에 수행한 작업의 완료시간이 정답이 아니라는 것이 중요!
    cout << *max_element(doneTime, doneTime + (N + 1));
}
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void makeGraph(vector<int> *g, vector<pair<int, int>> &nodeInfo, int V)
{
    for (int i = 1; i <= V; i++)
    {
        cin >> nodeInfo[i].first >> nodeInfo[i].second;

        for (int j = 0; j < nodeInfo[i].second; j++)
        {
            int workNum;
            cin >> workNum;
            g[workNum].push_back(i);
        }
    }
}

int ShortestProcessingTime(vector<int> *g, vector<pair<int, int>> &nodeInfo, int V)
{
    queue<int> q;
    vector<int> spendTime(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (nodeInfo[i].second == 0)
        {
            q.push(i);
            spendTime[i] = nodeInfo[i].first;
        }
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < g[now].size(); i++)
        {
            int next = g[now][i];
            nodeInfo[next].second--;

            if (spendTime[next] < spendTime[now] + nodeInfo[next].first)
                spendTime[next] = spendTime[now] + nodeInfo[next].first;

            if (nodeInfo[next].second == 0)
                q.push(next);
        }
    }

    return *max_element(spendTime.begin(), spendTime.end());
}

int main()
{
    int N;
    cin >> N;

    vector<int> graph[N + 1];
    vector<pair<int, int>> nodeInfo(N + 1); // { first : workTime, second : indegree}

    makeGraph(graph, nodeInfo, N);

    cout << ShortestProcessingTime(graph, nodeInfo, N);
}