/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void makeGraph(vector<pair<int,int>> *node, int E)
{
    while(E--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }
}

pair<int,int> BFS(vector<pair<int,int>> *node, int V, int start)
{
    queue<int> q;
    bool check[V + 1] = {false};
    int distance[V + 1] = {0};

    distance[start] = 0;
    check[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < node[now].size();i++)
        {
            int next = node[now][i].first;
            if(!check[next])
            {
                distance[next] = distance[now] + node[now][i].second;
                check[next] = true;
                q.push(next);
            }
        }
    }

    int maxIndex = max_element(distance, distance + V + 1) - distance;

    return make_pair(maxIndex, distance[maxIndex]);
}

int getDiameter(vector<pair<int,int>> *node, int V)
{
    pair<int, int> ans = BFS(node, V, 1);

    ans = BFS(node, V, ans.first);

    return ans.second;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<pair<int,int>> node[n + 1];
    makeGraph(node, n - 1);

    cout << getDiameter(node, n);
}
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

pair<int,int> BFS(vector<pair<int,int>> *node, int V, int start)
{
    queue<int> q;
    bool check[V + 1] = {false};
    int distance[V + 1] = {0};

    distance[start] = 0;
    check[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < node[now].size();i++)
        {
            int next = node[now][i].first;
            if(!check[next])
            {
                distance[next] = distance[now] + node[now][i].second;
                check[next] = true;
                q.push(next);
            }
        }
    }

    int maxDistanceIndex = max_element(distance, distance + V + 1) - distance;

    return make_pair(maxDistanceIndex, distance[maxDistanceIndex]);
}

void makeGrpah(vector<pair<int,int>> *node, int V)
{
    int E = V - 1;
    while(E--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }
}

int getDiameter(vector<pair<int,int>> *node, int V)
{
    pair<int, int> ans = BFS(node, V, 1);
    ans = BFS(node, V, ans.first);

    return ans.second;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int>> node[n + 1];
    makeGrpah(node, n);
    cout << getDiameter(node, n);
}