/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int v, c;
};

void BFS(vector<edge> *node, int *depth, int (*parent)[2], int V, int start)
{
    queue<int> q;
    bool check[V + 1] = {false};

    check[start] = true;
    parent[start][0] = -1;
    parent[start][1] = 0;
    depth[start] = 0;
    q.push(start);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < node[now].size();i++)
        {
            int next = node[now][i].v;
            if(!check[next])
            {
                check[next] = true;
                parent[next][0] = now;
                parent[next][1] = node[now][i].c;
                depth[next] = depth[now] + 1;
                q.push(next);
            }
        }
    }
}

void makeGraph(vector<edge> *node, int *depth, int (*parent)[2],int V)
{
    int E = V - 1;
    while(E--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edge e1;
        e1.v = v;
        e1.c = c;
        node[u].push_back(e1);
        edge e2;
        e2.v = u;
        e2.c = c;
        node[v].push_back(e2);
    }

    BFS(node, depth, parent, V, 1);
}

int LCA(int *depth, int (*parent)[2], int u, int v)
{
    int distance_u = 0;
    int distance_v = 0;
    while(depth[u] > depth[v])
    {
        distance_u += parent[u][1];
        u = parent[u][0];
    }
    
    while(depth[u] < depth[v])
    {
        distance_v += parent[v][1];
        v = parent[v][0];
    }

    while(u != v)
    {
        distance_u += parent[u][1];
        u = parent[u][0];
        distance_v += parent[v][1];
        v = parent[v][0];
    }
    return distance_u + distance_v;
}

int main()
{
    int N;
    cin >> N;

    vector<edge> node[N + 1];
    int depth[N + 1] = {0};
    int parent[N + 1][2] = {0};

    makeGraph(node, depth, parent, N);

    int M;
    cin >> M;
    while(M--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(depth, parent, u, v)<<"\n";
    }
}
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<pair<int,int>> *node, int V, int *p, int * distance, int *depth)
{
    queue<int> q;
    bool check[V + 1] = {false};

    p[1] = 0;
    distance[1] = 0;
    depth[1] = 0;
    check[1] = true;
    q.push(1);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < node[now].size();i++)
        {
            int next = node[now][i].first;
            if(!check[next])
            {
                p[next] = now;
                distance[next] = node[now][i].second;
                depth[next] = depth[now] + 1;
                check[next] = true;
                q.push(next);
            }
        }
    }
}

void makeGraph(vector<pair<int,int>> *node, int *p, int * distance, int *depth,int V)
{
    int E = V - 1;
    while(E--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }
    BFS(node, V, p, distance, depth);
}

int LCA(int *parent, int *distance, int *depth,int u, int v)
{
    int nodeDistance = 0;
    if(depth[u] < depth[v])
        swap(u, v);

    // depth[u] > depth[v]

    while(depth[u] !=  depth[v])
    {
        nodeDistance += distance[u];
        u = parent[u];
    }

    while(u != v)
    {
        nodeDistance += distance[u];
        u = parent[u];
        nodeDistance += distance[v];
        v = parent[v];
    }

    return nodeDistance;
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int,int>> node[N + 1];
    int depth[N + 1];
    int parent[N + 1];
    int distanceToParent[N + 1];
    
    makeGraph(node, parent, distanceToParent, depth, N);

    int M;
    cin >> M;
    while(M--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(parent, distanceToParent, depth, u, v)<<"\n";
    }
}