#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    string input;
    cin >> input;

    vector<vector<int>> DP;

    for (int i = 0; i < N + 1; i++)
    {
        vector<int> a(N + 1);
        for (int j = 0; j < N + 1; j++)
        {
            DP.push_back(a);
            DP[i][j] = j;
        }
    }

    // for (int i = 0; i < N + 1; i++)
    // {
    //     for (int j = 0; j < N + 1; j++)
    //         cout << DP[i][j];
    //     cout << "\n";
    // }

    for (int i = 0; i < N + 1; i++)
    {
        if (input[i] == '.')
            continue;
        else if (input[i] == '(')
        {
            auto iter = find(input.rbegin(), input.rend(), ')');
            cout << *iter;
        }
    }
}