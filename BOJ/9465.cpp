#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> &score, int n)
{
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n,vector<int>(2,0)));

    dp[0][0][1] = score[0][0];
    dp[0][0][0] = 0;

    for(int j = 1; j < n; j++)
    {
        dp[0][j][0] = max(dp[0][j-1][0], dp[0][j-1][1]);
        dp[0][j][1] = score[0][j] + dp[0][j-1][0];
    }

    dp[1][0][1] = score[1][0] + dp[0][0][0];
    dp[1][0][0] = max(dp[0][0][0], dp[0][0][1]);

    for(int j = 1; j < n; j++)
    {
        dp[1][j][0] = max(max(dp[0][j][0],dp[0][j][1]), max(dp[1][j-1][0],dp[1][j-1][1]));
        dp[1][j][1] = score[1][j] + max(dp[0][j][0], dp[1][j-1][0]);
    }

    return max(dp[1][n-1][0], dp[1][n-1][1]);
}

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int n;
        scanf("%d", &n);
        vector<vector<int>> score(2, vector<int>(n,0));

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &score[i][j]);

        printf("%d\n", solution(score,n));
    }
}