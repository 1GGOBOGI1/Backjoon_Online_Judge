#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int check_ans(int *game,vector<pair<int,int>>inside)
{
    while (!inside.empty())
    {
        int x = inside.back().first;
        int y = inside.back().second;

        inside.pop_back();

        game[x][y] = 0;

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x > 0 && next_x < N + 1 && next_y > 0 && next_y < N + 1)
            {
                if (game[next_x][next_y] == 1)
                {
                    game[next_x][next_y] = 0;
                    auto iter = find(inside.begin(), inside.end(), make_pair(next_x, next_y));
                    inside.erase(iter);
                }
                else
                {
                    game[next_x][next_y] = 1;
                    inside.push_back(make_pair(next_x, next_y));
                }
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};

    int game[N + 1][N + 1];
    memset(game, 0, sizeof(game));
    vector<pair<int,int>> inside;
    string input;
    cin >> input;
    for (int i = 0; i < input.size();i++)
        if (input[i] =='#')
        {
            game[1][i + 1] = 1;
            inside.push_back(make_pair(1, i + 1));
        }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
            cout << game[i][j] << " ";
        cout << "\n";
    }

    while(!inside.empty())
    {
        int x = inside.back().first;
        int y = inside.back().second;

        inside.pop_back();

        game[x][y] = 0;

        for (int i = 0; i < 4;i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x > 0 && next_x < N + 1&&next_y>0&&next_y<N+1)
            {
                if(game[next_x][next_y]==1)
                {
                    game[next_x][next_y] = 0;
                    auto iter = find(inside.begin(), inside.end(), make_pair(next_x, next_y));
                    inside.erase(iter);
                }
                else
                {
                    game[next_x][next_y] = 1;
                    inside.push_back(make_pair(next_x, next_y));
                }
            }
        }
    }

    for (int i = 1; i < N + 1;i++)
    {
        for (int j = 1; j < N + 1; j++)
            cout << game[i][j] << " ";
        cout << "\n";
    }
        
}