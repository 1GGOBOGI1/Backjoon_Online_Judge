#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int totalVirus = 0;

queue<pair<int, int>> initial_position;

void BFS(vector<vector<int>> room)
{
    queue<pair<int, int>> q = initial_position;
    vector<vector<bool>> check(N, vector<bool>(M, false));

    int virus = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        room[x][y] = 2;
        virus++;
        q.pop();

        if (x - 1 >= 0 && !check[x - 1][y] && room[x - 1][y] == 0)
        {
            check[x - 1][y] = true;
            q.push(make_pair(x - 1, y));
        }

        if (x + 1 < N && !check[x + 1][y] && room[x + 1][y] == 0)
        {
            check[x + 1][y] = true;
            q.push(make_pair(x + 1, y));
        }

        if (y - 1 >= 0 && !check[x][y - 1] && room[x][y - 1] == 0)
        {
            check[x][y - 1] = true;
            q.push(make_pair(x, y - 1));
        }

        if (y + 1 < M && !check[x][y + 1] && room[x][y + 1] == 0)
        {
            check[x][y + 1] = true;
            q.push(make_pair(x, y + 1));
        }
    }

    if(totalVirus > virus)
        totalVirus = virus;

    return ;
}

void makeWall(int remainWall, vector<vector<int>> room)
{
    if (remainWall == 0)
    {
        // 탐색 시작
        BFS(room);
        return;
    }

    // 벽 세움
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (room[i][j] == 0)
            {
                room[i][j] = 1;
                makeWall(remainWall - 1, room);
                room[i][j] = 0;
            }
}

int main()
{
    scanf("%d %d", &N, &M);

    vector<vector<int>> room(N, vector<int>(M));
    int total_wall = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &room[i][j]);
            if (room[i][j] == 2)
                initial_position.push(make_pair(i, j));
            else if(room[i][j] == 1)
                total_wall++;
        }

    total_wall += 3;
    totalVirus = N * M;
    makeWall(3, room);
    printf("%d", N * M - totalVirus - total_wall);
}