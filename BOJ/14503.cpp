#include <iostream>
#include <vector>
using namespace std;

struct position
{
    int i;
    int j;
    position(int _i, int _j) : i(_i), j(_j) {}
};

position turn_left(int r, int c, int d)
{
    switch (d)
    {
    case 0:
        return position(r, c - 1);
    case 1:
        return position(r - 1, c);
    case 2:
        return position(r, c + 1);
    case 3:
        return position(r + 1, c);
    }
}

position go_back(int r, int c, int d)
{
    switch (d)
    {
    case 0:
        return position(r + 1, c);
    case 1:
        return position(r, c - 1);
    case 2:
        return position(r - 1, c);
    case 3:
        return position(r, c + 1);
    }
}

int change_dir(int d)
{
    return d-1 < 0 ? 3 : d-1;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector<int>> room(N, vector<int>(M, 0));

    int r, c, d;
    scanf("%d %d %d", &r, &c, &d);
    // d -> 0: 북, 1: 동, 2: 남, 3: 서

    int input;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &input);
            room[i][j] = input;
        }

    int answer = 0;

    while (true)
    {
        if (room[r][c] == 0)
        {
            answer++;
            room[r][c] = 2;
        }

        position next = turn_left(r, c, d);

        if (room[next.i][next.j] == 0)
        {
            r = next.i;
            c = next.j;
            d = change_dir(d);
        }
        else if (room[r - 1][c] >= 1 && room[r + 1][c] >= 1 && room[r][c - 1] >= 1 && room[r][c + 1] >= 1)
        {
            position back = go_back(r, c, d);

            if (room[back.i][back.j] == 1)
                break;

            r = back.i;
            c = back.j;
        }
        else
            d = change_dir(d);
    }

    printf("%d", answer);
}