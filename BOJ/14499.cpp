#include <iostream>
#include <vector>
using namespace std;

struct Dice
{
    int dice[4][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 3, j = 1;

    int get_front()
    {
        if (j == 1)
            return dice[(i + 2) % 4][1];
        else
            return j == 0 ? dice[1][2] : dice[1][0];
    }

    void print_dice()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
                printf("%d ", dice[i][j]);
            printf("\n");
        }
    }

    int move_dice(int move_to)
    {
        switch (move_to)
        {
        case 1:
            j = (j + 1) % 3;
            break;
        case 2:
            j = j - 1 >= 0 ? j - 1 : 2;
            break;
        case 4:
            i = i - 1 >= 0 ? i - 1 : 3;
            break;
        case 3:
            i = (i + 1) % 4;
            break;
        }

        return get_front();
    }

    void change_num(int num)
    {
        dice[i][j] = num;
    }

    int get_num()
    {
        return dice[i][j];
    }
};

int main()
{
    int N, M, x, y, K;
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

    vector<vector<int>> map(N, vector<int>(M, 0));

    int input;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);

    Dice d;

    while (K--)
    {
        scanf("%d", &input);

        d.print_dice();

        switch (input)
        {
        case 1:
            if (y + 1 < M)
            {
                y = y + 1;
                printf("%d\n", d.move_dice(1));
                if (map[x][y] == 0)
                    map[x][y] = d.get_num();
                else
                {
                    d.change_num(map[x][y]);
                    map[x][y] = 0;
                }
            }
            break;
        case 2:
            if (y - 1 >= 0)
            {
                y = y - 1;
                printf("%d\n", d.move_dice(2));
                if (map[x][y] == 0)
                    map[x][y] = d.get_num();
                else
                {
                    d.change_num(map[x][y]);
                    map[x][y] = 0;
                }
            }
            break;
        case 3:
            if (x - 1 >= 0)
            {
                x = x - 1;
                printf("%d\n", d.move_dice(3));
                if (map[x][y] == 0)
                    map[x][y] = d.get_num();
                else
                {
                    d.change_num(map[x][y]);
                    map[x][y] = 0;
                }
            }
            break;
        case 4:
            if (x + 1 < N)
            {
                x = x + 1;
                printf("%d\n", d.move_dice(4));
                if (map[x][y] == 0)
                    map[x][y] = d.get_num();
                else
                {
                    d.change_num(map[x][y]);
                    map[x][y] = 0;
                }
            }
            break;
        }
    }
}