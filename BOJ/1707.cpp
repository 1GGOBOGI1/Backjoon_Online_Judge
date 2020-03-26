#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void makeGraph(int E, vector<int> *g)
{
    for (int j = 0; j < E; j++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

bool bfs(vector<int> *g,bool *check, int *color, int v)
{
    queue<int> q;

    check[v] = true;
    color[v] = 1;
    q.push(v);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < g[now].size();i++)
        {
            int next = g[now][i];
            if(!check[next])
            {
                check[next] = true;
                color[next] = color[now] * -1;
                q.push(next);
            }
            else
                if(color[now] == color[next])
                        return false;
            
        }
    }
    return true;
}

string isBipartiteGraph(vector<int> *g, int V)
{
    bool check[V + 1] = {false};
    int color[V + 1];

    for (int i = 1; i <= V;i++)
    {
        if(!check[i])
        {
            color[i] = 1;
            if(!bfs(g,check,color,i))
                return "NO";
        }
    }
    return "YES";
}

int main()
{
    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int V, E;
        cin >> V >> E;

        vector<int> g[V + 1];
        
        makeGraph(E, g);

        cout << isBipartiteGraph(g, V) <<"\n";
    }
}