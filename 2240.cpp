#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int _max = 0;

void solve(int t, int w, int tree[], int ans, int location)
{
    if (t == 0)
    {
        if (_max < ans)
            _max = ans;
        return;
    }

    if (location == tree[t])
    {
        ans++;
    }

    solve(t - 1, w, tree, ans, location);
    if (location == 1)
        location = 2;
    else
        location = 1;
    if (w > 0)
        solve(t - 1, w - 1, tree, ans, location);
}

int main()
{
    int T, W;
    cin >> T >> W;
    int tree[T + 1] = {0};
    for (int i = T; i > 0; i--)
        cin >> tree[i];

    solve(T, W, tree, 0, 1);

    cout << _max;
}*/

int main()
{
    int T, W;
    cin >> T >> W;

    int tree[T + 1] = {0};
    int DP[1001][33][3] = {0};

    for (int i = 1; i < T + 1; i++)
        cin >> tree[i];

    
    for (int i = 2; i < T + 1; i++)
    {
        for (int j = 1; j <= W + 1; j++)
        {
            if (tree[i] == 1)
            {
                DP[i][j][1] = max(DP[i - 1][j][1] + 1, DP[i - 1][j - 1][2] + 1);
                DP[i][j][2] = max(DP[i - 1][j][2], DP[i - 1][j - 1][1]);
            }
            else
            {
                DP[i][j][1] = max(DP[i - 1][j - 1][2], DP[i - 1][j][1]);
                DP[i][j][2] = max(DP[i - 1][j - 1][1] + 1, DP[i - 1][j][2] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= W + 1; i++)
    {
        int _max = max(DP[T][i][1], DP[T][i][2]);
        if (ans < _max)
            ans = _max;
    }
    cout << ans;
}