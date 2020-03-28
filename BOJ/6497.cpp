#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        return a.second > b.second;
    }
};

void makeGraph(vector<pair<int,int>> *g, int E)
{
    for (int i = 0;i<E;i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
}

void Prim(vector<pair<int,int>>,int V)
{
    bool check[V + 1] = {false};
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

    
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int m, n;
        cin >> m >> n;

        vector<pair<int,int>> graph[m + 1];
    }
}