#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct planet
{
    int num, x, y, z;
};

struct tunnel
{
    int u, v, c;

    tunnel(int _u, int _v, int _c)
    {
        u = _u;
        v = _v;
        c = _c;
    }
};

struct comparePriorityQueue
{
    bool operator()(tunnel a, tunnel b)
    {
        return a.c > b.c;
    }
};

struct comparePlanet
{
    int _case;
    comparePlanet(int _case) { this->_case = _case; }
    bool operator()(planet a, planet b)
    {
        switch (_case)
        {
        case 0:
            return a.x < b.x;
            break;
        case 1:
            return a.y < b.y;
            break;
        case 2:
            return a.z < b.z;
            break;
        }
    }
};

struct DisjointSet
{
    vector<int> parent, height;
    DisjointSet(int V) : parent(V + 1), height(V + 1, 1)
    {
        for (int i = 1; i <= V; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (height[u] > height[v])
            swap(u, v);

        parent[u] = v;

        if (height[u] == height[v])
            height[v]++;
    }
};

void addTunnel(vector<planet> &planetes, priority_queue<tunnel, vector<tunnel>, comparePriorityQueue> &tunneles, int V)
{
    for (int i = 0; i < 3; i++)
    {
        sort(planetes.begin(), planetes.end(), comparePlanet(i));

        for (int j = 1; j < V; j++)
        {int c = min(abs(planetes[j-1].x - planetes[j].x), min(abs(planetes[j-1].y - planetes[j].y), abs(planetes[j-1].z - planetes[j].z)));
            tunnel t(planetes[j-1].num, planetes[j].num, c);
            tunneles.push(t);
        }
    }
}

int Kruscal(priority_queue<tunnel, vector<tunnel>, comparePriorityQueue> &tunneles, int V)
{
    DisjointSet disjointSet(V);
    int cost = 0;
    int edge = 0;

    while (edge != V - 1)
    {
        int u = tunneles.top().u;
        int v = tunneles.top().v;
        int c = tunneles.top().c;
        if (disjointSet.find(u) != disjointSet.find(v))
        {
            disjointSet.merge(u, v);
            edge++;
            cost += c;
        }
        tunneles.pop();
    }

    return cost;
}

int main()
{
    int N;
    cin >> N;

    vector<planet> planetes(N);
    priority_queue<tunnel, vector<tunnel>, comparePriorityQueue> tunneles;
    for (int i = 0; i < N; i++)
    {
        planetes[i].num = i + 1;
        cin >> planetes[i].x >> planetes[i].y >> planetes[i].z;
    }

    addTunnel(planetes, tunneles, N);

    cout << Kruscal(tunneles, N);
}