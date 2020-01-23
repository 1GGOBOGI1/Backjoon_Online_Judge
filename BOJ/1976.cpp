#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind
{
    vector<int> parent, rank;
    int size;

    UnionFind(int n) : parent(n), rank(n,1)
    {
        size = n;
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if(u >= size)
            return 0;
        if (u == parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if(u == v)
            return;

        if(rank[u] > rank[v])
            swap(u, v);

        parent[u] = v;

        if(rank[u] == rank[v])
            ++rank[v];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, flag;
    cin >> N >> M;

    UnionFind uf(N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N;j++)
        {
            cin >> flag;
            if(flag == 1)
            {
                uf.merge(i, j);
            }
        }
    }
    int c1, c2;
    cin >> c1;
    c1 = uf.find(c1 - 1);

    for (int i = 1; i < M;i++)
    {
        cin >> c2;
        c2 = uf.find(c2 - 1);

        if(c1 != c2)
        {
            cout << "NO";
            return 0;
        }
        c1 = c2;
    }

    cout << "YES";
    return 0;
}