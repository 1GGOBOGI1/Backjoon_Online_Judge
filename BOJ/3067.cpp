#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> coins(N, 0);
        for (int i = 0; i < N; i++)
            cin >> coins[i];

        int M;
        cin >> M;
        vector<int> DP(M + 1, 0);

        DP[0] = 1;

        for (int i = 0; i < N; i++)
        {
            for (int j = coins[i]; j < M + 1; j++)
                DP[j] += DP[j - coins[i]];
        }

        cout << DP[M] << endl;
    }
}