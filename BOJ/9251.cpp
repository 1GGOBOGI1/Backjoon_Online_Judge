#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string str1, string str2)
{
    int score = 0;

    vector<vector<int>> DP(str1.length(), vector<int>(str2.length(), 0));

    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
        {

            if (str1[i] == str2[j])
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                else
                    DP[i][j] = 1;
            }
            else
            {
                if (i-1 >= 0 && j-1 >=0)
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                else if (j-1 >=0)
                    DP[i][j] = DP[i][j - 1];
                else if (i-1>=0)
                    DP[i][j] = DP[i - 1][j];
            }

            if (DP[i][j] > score)
            {
                score = DP[i][j];
            }
        }
    }

    return score;
}

int main()
{
    string str1;
    string str2;

    cin >> str1 >> str2;

    cout << LCS(str1, str2);
}