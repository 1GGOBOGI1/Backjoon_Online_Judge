#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
        cin >> num[i];

    vector<int> DP(n + 1, 0);
    DP[1] = num[1];
    for (int i = 2; i < n + 1; i++)
    {
        if (DP[i - 1] + num[i] >= num[i])
            DP[i] = DP[i - 1] + num[i];
        else
            DP[i] = num[i];
    }

    auto iter = max_element(DP.begin() + 1, DP.end());
    cout << *iter;
}