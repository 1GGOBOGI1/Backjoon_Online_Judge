#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet
{
private:
    vector<int> parent;
    vector<bool> isEmpty;

public:
    DisjointSet(int n) : parent(n + 1), isEmpty(n + 1, true)
    {
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int Find(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = Find(parent[u]);
    }

    void Merge(int now, int next)
    {
        now = Find(now);
        next = Find(next);

        parent[now] = next;
        isEmpty[now] = false;

        printf("LADICA\n");
    }

    bool isDrawerEmpty(int u)
    {
        return isEmpty[u];
    }
};

void solution(int N, int L)
{
    DisjointSet ds(L);

    while (N--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (ds.isDrawerEmpty(a))
        {
            ds.Merge(a, b);
        }
        else if (ds.isDrawerEmpty(b))
        {
            ds.Merge(b, a);
        }

        else if (ds.isDrawerEmpty(ds.Find(a)))
        {
            ds.Merge(a, b);
        }
        else if (ds.isDrawerEmpty(ds.Find(b)))
        {
            ds.Merge(b, a);
        }
        else
        {
            printf("SMECE\n");
        }
    }
}

int main()
{
    int N, L;
    scanf("%d %d", &N, &L);

    solution(N, L);
}