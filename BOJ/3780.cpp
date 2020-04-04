#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet
{
    vector<int> group;

    DisjointSet(int n) : group(n+1) {
        for (int i = 1; i <= n;i++)
            group[i] = i;
    }

    int find(int u)
    {
        if(u == group[u])
            return u;

        return group[u] = find(group[u]);
    }

    int merge(int a, int b)
    {
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        group[a] = b;
    }
};

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;

        vector<int> graph[N + 1];
        int center = 0;
    }
}