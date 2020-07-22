#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Query
{
    int command, a, b;
    Query(int _command, int _a, int _b):command(_command), a(_a),b(_b){}
};

struct DisjointSet
{
    vector<int> parent;

    DisjointSet(int n):parent(n+1) {
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int Find(int u)
    {
        if(u==parent[u])
            return u;

        return parent[u] = Find(parent[u]);
    }

    void Merge(int childNode, int parentNode)
    {
        childNode = Find(childNode);
        parentNode = Find(parentNode);

        if(childNode == parentNode)
            return;

        parent[childNode] = parentNode;
        return;
    }

    bool isRouteExists(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if(a == b)
            return true;

        return false;
    }
};

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);

    vector<int> parent(N + 1);
    parent[1] = 1;
    stack<Query> query;

    for (int i = 2; i < N+1; i++)
    {
        scanf("%d", &parent[i]);
    }

    for (int i = 0; i < N - 1 + Q;i++)
    {
        int command, a, b;
        scanf("%d", &command);

        switch(command)
        {
            case 0:
                scanf("%d", &b);
                query.push(Query(command, 0, b));
                break;
            case 1:
                scanf("%d %d", &a, &b);
                query.push(Query(command, a, b));
                break;
        }
    }

    DisjointSet ds(N);
    stack<string> ans;

    while(!query.empty())
    {
        Query q = query.top();
        query.pop();

        switch(q.command)
        {
            case 0:
                ds.Merge(q.b, parent[q.b]);
                break;
            case 1:
                ans.push(ds.isRouteExists(q.a, q.b) ? "YES" : "NO");
                break;
        }
    }

    while(!ans.empty())
    {
        printf("%s\n", ans.top().c_str());
        ans.pop();
    }
}