#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<int> *graph, int N, int start)
{
    queue<int> q;
    bool check[N + 1] = {false};
    int depth[N + 1] = {0};
    int maxDepth = 0;

    check[start] = true;
    depth[start] = 0;
    q.push(start);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size();i++)
        {
            int next = graph[now][i];
            if(!check[next])
            {
                depth[next] = depth[now] + 1;
                check[next] = true;
                q.push(next);
                if(maxDepth < depth[next])
                    maxDepth = depth[next];
            }
        }
    }

    return maxDepth;
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> graph[N + 1];
    int minDepth = N+1;
    vector<int> king;

    int a, b;
    while(true)
    {
        scanf("%d %d", &a, &b);

        if(a == -1 && b == -1)
            break;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        int d = BFS(graph, N, i);
        if(minDepth > d)
        {
            minDepth = d;
            king.clear();
            king.push_back(i);
        }
        else if(minDepth == d)
            king.push_back(i);
    }

    printf("%d %lld\n", minDepth, king.size());
    for (int i = 0; i < king.size();i++)
        printf("%d ", king[i]);
}   