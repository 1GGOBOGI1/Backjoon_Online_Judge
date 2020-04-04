#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans = 0;

char board[55][55];

void howManyCandy(int N)
{
    int cnt = 1;

    for (int i = 0; i < N; i++)
    {
        cnt = 1;
        for (int j = 0; j < N-1; j++)
        {
            if (board[i][j] == board[i][j + 1])
                cnt++;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        cnt = 1;
        for (int j = 0; j < N-1; j++)
        {
            if (board[j][i] == board[j + 1][i])
                cnt++;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
    }
}

int main()
{
    int N;
    cin >> N;

    //vector<string> board(N);
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i <= N-1; i++)
    {
        for (int j = 0; j < N-1; j++)
        {
            swap(board[i][j], board[i][j+1]);
            howManyCandy(N);
            swap(board[i][j], board[i][j+1]);

            swap(board[j][i], board[j+1][i]);
            howManyCandy(N);
            swap(board[j][i], board[j+1][i]);
        }
    }

    cout << ans;
}