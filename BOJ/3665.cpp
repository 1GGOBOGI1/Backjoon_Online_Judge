/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void makeGraph(vector<int> *g, int *indegree, int *lastYear, int V)
{
    for (int i = 1; i <= V; i++)
    {
        for (int j = i + 1; j <= V; j++)
        {
            int u = i;
            int v = j;
            if (lastYear[u] < lastYear[v])
                swap(u, v);

            g[v].push_back(u);
            indegree[u]++;
        }
    }
}

void changeGraph(vector<int> *g, int *indegree, int *lastYear)
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int u, v;
        cin >> u >> v;

        if (lastYear[u] < lastYear[v])
            swap(u, v);

        // lastYear[u] > lastYear[v] 작년에는 u가 v보다 못했음
        // v.pushback(u), indegree[u]++ 되어 있을 것

        g[v].erase(remove(g[v].begin(), g[v].end(), u), g[v].end());
        indegree[u]--;
        g[u].push_back(v);
        indegree[v]++;
    }
}

void TopologicalSort(vector<int> *g, int *indegree, int V)
{
    queue<int> q;
    queue<int> answer;

    for (int i = 1; i <= V; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int now = q.front();
        answer.push(now);
        q.pop();

        for (int i = 0; i < g[now].size(); i++)
        {
            int next = g[now][i];
            if (--indegree[next] == 0)
                q.push(next);
        }

        if (q.size() > 1)
        {
            cout << "?\n";
            return;
        }
    }

    if (answer.size() != V)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    while (!answer.empty())
    {
        cout << answer.front() << " ";
        answer.pop();
    }
    cout << "\n";
    return;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int lastYear[n + 1] = {0};
        vector<int> graph[n + 1];
        int indegree[n + 1] = {0};
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            lastYear[x] = i;
        }
        makeGraph(graph, indegree, lastYear, n);
        changeGraph(graph, indegree, lastYear);
        TopologicalSort(graph, indegree, n);
    }
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void makeGraph(vector<int> *graph, vector<int> &indegree, int *lastYear, int V)
{
    for (int i = 1; i <= V;i++)
    {
        for (int j = i + 1; j <= V;j++)
        {
            int u = i;
            int v = j;
            if(lastYear[u] < lastYear[v])
                swap(u, v);
            // lastYear[j] < lastYear[i] j가 i보다 순위가 높음
            graph[v].push_back(u);
            indegree[u]++;
        }
    }
}

void modifyGraph(vector<int> *graph, vector<int> &indegree, int *lastYear)
{
    int m;
    cin >> m;

    cout << "m = " << m << "\n";
    for (int i = 0; i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        cout << "a = " << a << "b = " << b << "\n";
        if(lastYear[a]<lastYear[b])
            swap(a, b);
        
        // lastYear[a] > lastYear[b] b가 a보다 순위 높음
        // graph[b].push_back(a), indegree[a]++ 되어 있을 것

        graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());
        indegree[a]--;

        graph[a].push_back(b);
        indegree[b]++;
    }
}

void TopologicalSort(vector<int> *graph, vector<int> &indegree, int V)
{
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

        if(q.size() > 1)
        {
            cout << "?\n";
            return;
        }
    }

    if(answer.size() != V)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    while(!answer.empty())
    {
        cout << answer.front() << " ";
        answer.pop();
    }
    cout << "\n";
    return;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;
        int lastYear[n + 1];

        for (int i = 1; i <= n;i++)
        {
            int t;
            cin >> t;
            lastYear[t] = i;
        }

        vector<int> graph[n + 1];
        vector<int> indegree(n + 1, 0);

        makeGraph(graph, indegree, lastYear, n);
        modifyGraph(graph, indegree, lastYear);
        TopologicalSort(graph, indegree, n);

    }
}