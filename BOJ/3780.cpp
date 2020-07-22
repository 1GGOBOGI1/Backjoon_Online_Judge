#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct DisjointSet
{
    vector<int> parent, distanceToParent;

    DisjointSet(int n) : parent(n + 1), distanceToParent(n + 1, 0)
    {
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if(u == parent[u])
            return u;

        int _parent = find(parent[u]);
        distanceToParent[u] += distanceToParent[parent[u]];
        parent[u] = _parent;

        return _parent;
    }


    void merge(int I, int J)
    {
        parent[I] = J;
        distanceToParent[I] = abs(I - J) % 1000;
    }

    int getDistance(int node)
    {
        find(node);
        return distanceToParent[node];
    }
};

void solution(int N)
{
    DisjointSet ds(N);

    char command;

    int I, J;
    do
    {
        scanf("%c", &command);

        switch (command)
        {
        case 'E':
            scanf("%d", &I);
            printf("%d\n", ds.getDistance(I));
            break;
        case 'I':
            scanf("%d %d", &I, &J);
            ds.merge(I, J);
            break;
        }
    } while (command != 'O');
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        solution(N);
    }
}