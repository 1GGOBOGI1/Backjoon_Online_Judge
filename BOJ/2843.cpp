#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Query
{
    int command, X;
    Query(int _command, int _X) : command(_command), X(_X) {}
};
struct DisjointSet
{
    vector<int> parent;
    vector<bool> cycle;

    DisjointSet(int n) : parent(n + 1), cycle(n+1,false)
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

    void Merge(int start, int end)
    {
        //printf("merge %d with %d\n", start, end);
        start = Find(start);
        end = Find(end);

        if (start == end)
        {
            if(!cycle[end])
            {
                //printf("check cycle %d\n", end);
                cycle[end] = true;
            }
            return;
        }
        //printf("%d's parent is %d\n", start, end);
        parent[start] = end;
    }

    int getDestination(int u)
    {
        u = Find(u);

        if(cycle[u])
            return -1;

        return u;
    }
};

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> originalParent(N + 1);
    vector<bool> remainEdge(N + 1, true);

    for (int i = 1; i <= N; i++)
        scanf("%d", &originalParent[i]);

    int Q;
    scanf("%d", &Q);
    stack<Query> query;

    while (Q--)
    {
        int command, X;
        scanf("%d %d", &command, &X);
        query.push(Query(command, X));

        if (command == 2)
            remainEdge[X] = false;
    }

    DisjointSet ds(N);

    for (int i = 1; i <= N; i++)
        if (remainEdge[i] && originalParent[i] != 0)
            ds.Merge(i, originalParent[i]);

    stack<string> ans;
    int destination = 0;
    while (!query.empty())
    {
        Query q = query.top();
        query.pop();

        switch (q.command)
        {
        case 1:
            ans.push((destination = ds.getDestination(q.X)) == -1 ? "CIKLUS" : to_string(destination));
            break;
        case 2:
            ds.Merge(q.X, originalParent[q.X]);
            break;
        }
    }

    while(!ans.empty())
    {
        printf("%s\n", ans.top().c_str());
        ans.pop();
    }
}