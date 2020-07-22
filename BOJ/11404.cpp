#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i < n + 1;i++)
        graph[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        graph[a][b] = min(graph[a][b], c);
    }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1;j++)
            for (int k = 1; k < n + 1;k++)
                if(graph[j][k] > graph[j][i] + graph[i][k])
                    graph[j][k] = graph[j][i] + graph[i][k];

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1;j++)
            printf("%d ", graph[i][j] == INF? 0 : graph[i][j]);
        printf("\n");
    }
}