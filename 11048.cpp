#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int room[N + 1][M + 1], DP[N + 1][M + 1] = {0};
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < M + 1; j++)
        {
            cin >> room[i][j];
        }
    }
    DP[1][1] = room[1][1];
    for (int i = 2; i < N + 1; i++)
        DP[i][1] = DP[i - 1][1] + room[i][1];
    for (int i = 2; i < M + 1; i++)
        DP[1][i] = DP[1][i - 1] + room[1][i];
    for (int i = 2; i < N + 1; i++)
    {
        for (int j = 2; j < M + 1; j++)
            DP[i][j] = max(max(DP[i - 1][j - 1], DP[i - 1][j]), DP[i][j - 1]) + room[i][j];
    }
    cout << DP[N][M];
}