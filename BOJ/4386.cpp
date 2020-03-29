#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct location
{
    int num;
    double x, y;
};

struct edge
{
    edge(int _u,int _v, double _c){
        u = _u;
        v = _v;
        c = _c;
    }
    int u, v;
    double c;
};
/*
struct compareLocation
{
    int _case;
    compareLocation(int n) { this->_case = n; }
    bool operator()(location a, location b)
    {
        switch (_case)
        {
        case 0:
            return a.x > b.x;
            break;
        case 1:
            return a.y > b.y;
            break;
        }
    }
};
*/

struct compareCost
{
    bool operator()(edge a, edge b)
    {
        return a.c > b.c;
    }
};

struct DisjointSet
{
    vector<int> parent, height;
    DisjointSet(int n):parent(n),height(n,0)
    {
        for (int i = 0;i<n;i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if(u == parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if(height[u] > height[v])
            swap(u, v);
        parent[u] = v;

        if(height[u] == height[v])
            height[v]++;
    }
};

void makeGraph(vector<location> &star, priority_queue<edge, vector<edge>, compareCost> &edges)
{
    for (int i = 0; i < star.size();i++)
    {
        for (int j = i + 1; j < star.size(); j++)
        {
            edge e(star[i].num, star[j].num, sqrt(pow(star[i].x - star[j].x, 2) + pow(star[i].y - star[j].y, 2)));
            edges.push(e);
        }
    }
}
/*
void makeGraph(vector<location> &star, priority_queue<edge, vector<edge>, compareCost> &edges)
{
    for (int i = 0; i < 2;i++)
    {
        sort(star.begin(), star.end(), compareLocation(i));

        for (int j = 1; j < star.size();j++)
        {
            edge e(star[i].num, star[j].num, sqrt(pow(star[i].x - star[j].x, 2) + pow(star[i].y - star[j].y, 2)));
            edges.push(e);
        }
    }
}
*/

double Kruscal(priority_queue<edge, vector<edge>, compareCost> &edges, int V)
{
    DisjointSet set(V);
    double totalCost = 0;
    while(!edges.empty())
    {
        int u = edges.top().u;
        int v = edges.top().v;
        double c = edges.top().c;
        edges.pop();

        if(set.find(u) == set.find(v)) continue;

        set.merge(u, v);
        totalCost += c;
    }

    return totalCost;
}

int main()
{
    int n;
    cin >> n;

    vector<location> star(n);
    priority_queue<edge, vector<edge>, compareCost> edges;

    for (int i = 0; i < n;i++)
    {
        star[i].num = i;
        cin >> star[i].x >> star[i].y;
    }

    makeGraph(star, edges);
    cout << Kruscal(edges, n);

}