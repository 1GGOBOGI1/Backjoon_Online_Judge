#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct UnionFind
{
    vector<int> parent, rank,num;

    int findParent(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void newFriend(int n)
    {
        parent.push_back(n);
        rank.push_back(1);
        num.push_back(1);
    }

    int merge(int u1, int u2)
    {
        u1 = findParent(u1);
        u2 = findParent(u2);

        if(u1 == u2)
        {
            return num[u1];
        }

        if(rank[u1] > rank[u2])
            swap(u1, u2);

        parent[u1] = u2;
        num[u2] += num[u1];

        if(rank[u1] == rank[u2])
            ++rank[u2];

        return num[u2];
    }
};

int main()
{
    int T, F;
    
    scanf("%d", &T);

    while(T--)
    {
        UnionFind uf;
        map<string, int> m;
        scanf("%d", &F);
        int friendSize = 0;

        while(F--)
        {
            char p1[21], p2[21];
            scanf("%s %s", &p1, &p2);
            if(m.count(p1) == 0)
            {
                m.insert(make_pair(p1, friendSize));
                uf.newFriend(m[p1]);
                friendSize++;
            }
            if(m.count(p2) == 0)
            {
                m.insert(make_pair(p2, friendSize));
                uf.newFriend(m[p2]);
                friendSize++;
            }
            printf("%d\n", uf.merge(m[p1], m[p2]));
        }
    }
}