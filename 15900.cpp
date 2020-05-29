#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int ROOT = 1;

bool BFS(vector<vector<int>> &graph, int N)
{
    bool check[N + 1];
    int depth[N + 1];
    int depth_sum = 0;
    memset(check, false, sizeof(check));

    queue<int> q;
    check[ROOT] = true;
    depth[ROOT] = 0;
    q.push(ROOT);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        bool isLeaf = true;

        for (int i = 0; i < graph[now].size();i++)
        {
            int next = graph[now][i];
            if(!check[next])
            {
                isLeaf = false;
                check[next] = true;
                depth[next] = depth[now] + 1;
                q.push(next);
            }
        }

        if(isLeaf)
        {
            depth_sum += depth[now];
        }
    }

    if(depth_sum % 2 == 0)
        return false;
    return true;
}

    int main()
{
    int N;
    scanf("%d", &N);

    vector<vector<int>> graph(N + 1, vector<int>());

    for (int i = 0; i < N-1; i ++)
    {
            int a, b;
            scanf("%d %d", &a, &b);

            graph[a].push_back(b);
            graph[b].push_back(a);
    }

    BFS(graph, N) ? printf("Yes") : printf("No");
}