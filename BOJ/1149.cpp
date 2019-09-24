#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cost[N + 1][3];
    int DP[N + 1][3] = {0};
    for (int i = 1; i < N + 1; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    for (int i = 1; i < N + 1; i++)
    {
        DP[i][0] = cost[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
        DP[i][1] = cost[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
        DP[i][2] = cost[i][2] + min(DP[i - 1][0], DP[i - 1][1]);
    }

    cout << min(min(DP[N][0], DP[N][1]), DP[N][2]);
}