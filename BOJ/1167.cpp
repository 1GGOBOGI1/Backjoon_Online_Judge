#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge
{
    int v;
    long long c;
};

void makeGraph(vector<edge> *node, int V)
{
    while(V--)
    {
        int u;
        cin >> u;
        edge e;
        for (cin >> e.v; e.v != -1; cin>>e.v)
        {
            cin >> e.c;
            node[u].push_back(e);
        }
    }
}

pair<int,int> BFS(vector<edge> *node, int V, int start)
{
    queue<int> q;
    bool check[V + 1] = {false};
    long long distance[V + 1] = {0};

    distance[start] = 0;
    check[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < node[now].size();i++)
        {
            edge next = node[now][i];
            if(!check[next.v])
            {
                distance[next.v] = distance[now] + next.c;
                check[next.v] = true;
                q.push(next.v);
            }
        }
    }

    int maxIndex = max_element(distance, distance + V + 1) - distance;

    return make_pair(maxIndex, distance[maxIndex]);
}

int getDiamater(vector<edge> *node, int V)
{
    pair<int, int> maxIndex = BFS(node, V, 1);
    maxIndex = BFS(node, V, maxIndex.first);

    return maxIndex.second;
}

int main()
{
    int V;
    cin >> V;

    vector<edge> node[V + 1];
    makeGraph(node, V);
    cout << getDiamater(node, V);
}