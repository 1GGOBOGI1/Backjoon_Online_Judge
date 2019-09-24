#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> num(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> DP(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i; j > 0; j--)
            cin >> num[i][i - j + 1];
    }

    DP[1][1] = num[1][1];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (DP[i + 1][j] < DP[i][j] + num[i + 1][j])
                DP[i + 1][j] = DP[i][j] + num[i + 1][j];
            if (DP[i + 1][j + 1] < DP[i][j] + num[i + 1][j + 1])
                DP[i + 1][j + 1] = DP[i][j] + num[i + 1][j + 1];
        }
    }

    auto iter = max_element(DP[n].begin(), DP[n].end());

    cout << *iter;
}