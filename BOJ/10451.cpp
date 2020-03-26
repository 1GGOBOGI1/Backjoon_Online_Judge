#include <iostream>
#include <queue>
using namespace std;

void bfs(int * g, bool *check, int v)
{
    queue<int> q;
    q.push(v);
    check[v] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        int next = g[now];
        if(!check[next])
        {
            q.push(next);
            check[next] = true;
        }
    }
}

int getPermutationCycle(int *g, int N)
{
    int cycle = 0;
    bool check[N + 1] = {false};

    for (int i = 1; i <= N;i++)
    {
        if(!check[i])
        {
            bfs(g, check, i);
            cycle++;
        }
    }
    return cycle;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T;i++)
    {
        int N;
        cin >> N;

        int permutation[N + 1];
        for (int j = 1; j <= N;j++)
            cin >> permutation[j];

        cout << getPermutationCycle(permutation, N) << "\n";
    }
}