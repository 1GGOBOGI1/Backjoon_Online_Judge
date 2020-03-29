#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdio>
using namespace std;

struct location
{
    int x, y, num;
};

struct edge
{
    edge (location a, location b) {
        this->u = a.num;
        this->v = b.num;
        this->c = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }
    int u, v;
    long double c;
};

struct cmp
{
    bool operator()(edge a, edge b){
        return a.c > b.c;
    }
};

/*
struct sortByLocation
{
    int _case;
    sortByLocation(int input) { this->_case = input; }

    bool operator()(location a, location b){
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

struct DisjointSet
{
    vector<int> parent, height;
    DisjointSet(int n):parent(n),height(n){
        for (int i = 0; i < n;i++)
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

        if(u == v)
            return;

        if(height[u] > height[v])
            swap(u, v);

        parent[u] = v;

        if(height[u] == height[v])
            height[v]++;
    }
};

void setLocation(vector<location> &spaceGod, int V)
{
    for (int i = 0; i < V;i++)
    {
        spaceGod[i].num = i;
        cin >> spaceGod[i].x >> spaceGod[i].y;
    }
}

void makeEdges(priority_queue<edge, vector<edge>, cmp> &q, DisjointSet &set,vector<location> &spaceGod, int E)
{
    for (int i = 0; i < E;i++)
    {
        int u, v;
        cin >> u >> v;

        if(set.find(u - 1)== set.find(v - 1))
            continue;

        set.merge(u-1, v-1);
    }
    /*
    for (int i = 0; i < 2;i++)
    {
        sort(spaceGod.begin(), spaceGod.end(), sortByLocation(i));

        for (int j = 1; j < spaceGod.size();j++)
        {
            edge e(spaceGod[j - 1], spaceGod[j]);
            q.push(e);
        }
    }
    */

    for (int i = 1; i < spaceGod.size();i++)
    {
        edge e(spaceGod[i - 1], spaceGod[i]);
        q.push(e);
    }
}

long double Kruscal(priority_queue<edge, vector<edge>, cmp> &q, DisjointSet &set)
{
    long double cost = 0;
    while(!q.empty())
    {
        int u = q.top().u;
        int v = q.top().v;
        long double c = q.top().c;
        q.pop();
        
        // cout << "u = " << u << " v = " << v << "\n";
        // cout << "cost = " << c << "\n";

        if(set.find(u) == set.find(v))
        {
            //cout << "continue\n";
            continue;
        }
        //cout << "merge\n";
        set.merge(u, v);
        cost += c;
    }

    return cost;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<location> spaceGod(N);
    priority_queue<edge, vector<edge>, cmp> q;
    DisjointSet set(N);

    setLocation(spaceGod, N);
    makeEdges(q, set,spaceGod,M);

    /*
    cout << fixed;
    cout.precision(2);
    cout << round(Kruscal(q, set)*100)/100;
    */
    long double answer = Kruscal(q, set);
    printf("%.2lf\n", answer);
}