#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n + 1), rank(n + 1, 1)
    {
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int Find(int v)
    {
        if (v == parent[v])
            return v;

        return parent[v] = Find(parent[v]);
    }

    void Merge(int u, int v)
    {
        u = Find(u);
        v = Find(v);

        if (u == v)
            return;

        if (u < v)
            swap(u, v);

        // always u > v
        parent[u] = v;
        return;
    }

    bool Docking(int v)
    {
        v = Find(v);

        if (v == 0)
            return false;

        Merge(v, v - 1);
        return true;
    }
};

int solution(int G, int P, vector<int> &plane)
{
    UnionFind uf(G);

    for (int i = 0; i < P; i++)
    {
        if (!uf.Docking(plane[i]))
            return i;
    }

    return P;
}

int main()
{
    int G, P;

    scanf("%d", &G);
    scanf("%d", &P);

    vector<int> plane(P, 0);

    for (int i = 0; i < P; i++)
        scanf("%d", &plane[i]);

    printf("%d", solution(G, P, plane));
}