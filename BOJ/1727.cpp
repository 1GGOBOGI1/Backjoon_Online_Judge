#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long DP[1001][1001];

long long solution(vector<int> &man, vector<int> &woman)
{

    int n = man.size();
    int m = woman.size();

    sort(man.begin(), man.end());
    sort(woman.begin(), woman.end());

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            DP[i][j] = DP[i - 1][j - 1] + abs(man[i - 1] - woman[j - 1]);
            if (i > j)
            {
                DP[i][j] = min(DP[i][j], DP[i - 1][j]);
            }
            else if (i < j)
                DP[i][j] = min(DP[i][j], DP[i][j - 1]);
        }
    }

    return DP[n][m];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> man(n);
    vector<int> woman(m);

    for (int i = 0; i < n; i++)
        scanf("%d", &man[i]);

    for (int i = 0; i < m; i++)
        scanf("%d", &woman[i]);

    printf("%lld", solution(man, woman));
}