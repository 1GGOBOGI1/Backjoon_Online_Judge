#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    sort(coins, coins + n);
    int DP[k + 1] = {1};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
        {
            if (j + coins[i] >= k + 1)
                break;
            DP[j + coins[i]] += DP[j];
        }

    cout << DP[k];
}