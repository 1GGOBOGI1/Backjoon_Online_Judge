#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
      int N;
      cin >> N;
      vector<int> card(N + 1, 0);
      vector<int> DP(N + 1, 0);
      for (int i = 1; i < N + 1; i++)
            cin >> card[i];
      for (int i = 1; i < N + 1; i++)
      {
            DP[i] = card[i];
            for (int j = 1; i - j >= 1; j++)
            {
                  DP[i] = max(DP[i], DP[i - j] + card[j]);
            }
      }
      cout << DP[N];
}