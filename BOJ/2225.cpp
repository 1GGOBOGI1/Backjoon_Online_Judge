#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    vector<vector<int>> DP(K + 1, vector<int>(N + 1, 0));

    for (int i = 0; i <= N; i++)
        DP[1][i] = 1;

    for (int k = 1; k <= K; k++)
        for (int n = 0; n <= N; n++)
            for (int m = 0; m <= n; m++)
            {
                DP[k][n] += DP[k - 1][n - m];
                DP[k][n] %= 1000000000;
            }

    printf("%d", DP[K][N]);
}