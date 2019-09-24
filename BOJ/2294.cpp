#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 99999

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    sort(coins.begin(), coins.end());
    coins.erase(unique(coins.begin(), coins.end()), coins.end());

    int DP[k + 1];

    for (int i = 0; i < k + 1; i++)
        DP[i] = 999999;

    DP[0] = 0;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            int last = j - coins[i] * (j / coins[i]);
            int cnt = j / coins[i];
            /* cout << "j = " << j << endl;
            cout << "coin = " << coins[i] << " last = " << last << endl;
            cout << "DP[last] = " << DP[last] << endl; */

            for (int x = cnt; x >= 0;x--)
            {
                if (DP[j] > x + DP[last+coins[i]*(cnt-x)])
                {
                    DP[j] = x + DP[last + coins[i] * (cnt - x)];
                    // cout << "DP[j] = " << DP[j] << endl;
                }
            }
                
        }
    }

    /* for (int i = 0; i < k + 1; i++)
    {
        cout << DP[i] << " ";
    } */

    if (DP[k] == 999999)
        DP[k] = -1;
    cout << DP[k];
}