#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void makeGraph(vector<int> *graph, vector<int> &indegree, int k)
{
    string input;
    for (int i = 0; i < k; i++)
    {
        cin >> input;

        if (input.compare("<") == 0)
        {
            graph[i].push_back(i + 1);
            indegree[i + 1]++;
        }
        else
        {
            graph[i + 1].push_back(i);
            indegree[i]++;
        }
    }
}

void TopologicalSort(vector<int> *g, vector<int> indegree, int V)
{
    priority_queue<int, vector<int>, less<int>> lessQueue; // 내림차순
    vector<int> lessIndegree = indegree;
    int lessAnswer[V + 1];
    
    priority_queue<int> greaterQueue; // 오름차순
    vector<int> greaterIndegree = indegree;
    int greaterAnswer[V + 1];

    for (int i = 0; i <= V; i++)
    {
        if (indegree[i] == 0)
        {
            lessQueue.push(i);
            greaterQueue.push(i);
        }
    }

    int cnt = 0;

    while(!lessQueue.empty())
    {
        int index = -lessQueue.top();
        lessQueue.pop();
        lessAnswer[index] = cnt;
        cnt++;
        for (int i = 0; i < g[index].size();i++)
            if( --lessIndegree[g[index][i]] == 0)
                lessQueue.push(-g[index][i]);
    }

    cnt = 0;

    while(!greaterQueue.empty())
    {
        int index = greaterQueue.top();
        greaterQueue.pop();
        greaterAnswer[index] = cnt++;
        for (int i = 0; i < g[index].size();i++)
            if( --greaterIndegree[g[index][i]] == 0)
                greaterQueue.push(g[index][i]);
    }


    for (int i = 0; i <= V;i++)
        cout << greaterAnswer[i] + 9 - V;
    
    cout << "\n";

    for (int i = 0; i <= V;i++)
        cout << lessAnswer[i];

        
}

int main()
{
    int k;
    cin >> k;

    vector<int> graph[k + 1];
    vector<int> indegree(k + 1, 0);
    makeGraph(graph, indegree, k);

    TopologicalSort(graph, indegree, k);
}