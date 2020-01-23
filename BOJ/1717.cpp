#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind 
{
    vector<int> parent, rank;

    UnionFind(int n) : parent(n + 1), rank(n + 1, 1)
    {
        for (int i = 0; i < n + 1;i++)
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

        if(u==v)
            return;

        if(rank[u]>rank[v])
            swap(u, v);

        parent[u] = v;
        if(rank[u]==rank[v])
            ++rank[v];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, p, a, b;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m;i++)
    {
        cin >> p >> a >> b;

        if(p == 0)
            uf.merge(a, b);
        else
        {
            a = uf.find(a);
            b = uf.find(b);
            if(a==b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}