#include <iostream>
#include <array>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int coin[N];
        for (int i = 0; i < N; i++)
            cin >> coin[i];

        int M;
        cin >> M;
        long dp[M] = {1};

        for (int i = 0; i < N; i++)
            cout << coin[i] << " ";
        cout << endl;
        for (int i = 0; i < N; i++)
            for (int j = coin[i]; j <= M; j++)
                dp[j] += dp[j - coin[i]];

        cout << dp[M] << endl;
    }
}

#include <iostream>
using namespace std;
void answer(int N, int M);

int ans = 0;

int main()
{
    int N, M;
    cin >> N >> M;
    answer(N, M);
    cout << ans;
}

void answer(int N, int M)
{
    if (N == 1 && M == 1)
        return;
    ans++;
    if (N > M)
    {
        answer(N / 2, M);
        answer(N / 2 + N % 2, M);
    }
    else
    {
        answer(N, M / 2);
        answer(N, M / 2 + M % 2);
    }
}

#include <iostream>

using namespace std;

int main()
{
    int num[1001];
    int k;
    cin >> k;
    num[1] = 1;
    num[2] = 3;
    for (int i = 3; i <= k; i++)
        num[i] = (num[i - 1] + num[i - 2] * 2) % 10007;
    cout << num[k];
}