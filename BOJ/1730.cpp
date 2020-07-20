#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

struct position
{
    int row, col;
    position(int _row, int _col) : row(_row), col(_col) {}
};

bool canGo(position p, int n, char direction)
{
    switch (direction)
    {
    case 'U':
        if (p.row - 1 >= 0)
            return true;
        else
            return false;
    case 'D':
        if (p.row + 1 < n)
            return true;
        else
            return false;
    case 'L':
        if (p.col - 1 >= 0)
            return true;
        else
            return false;
    case 'R':
        if (p.col + 1 < n)
            return true;
        else
            return false;
    }
}

position nextPosition(position p, char direction)
{
    switch (direction)
    {
    case 'U':
        return position(p.row - 1, p.col);
    case 'D':
        return position(p.row + 1, p.col);
    case 'L':
        return position(p.row, p.col - 1);
    case 'R':
        return position(p.row, p.col + 1);
    }
}

position drawLine(vector<bitset<101>> &bitmask, vector<vector<int>> &pic, position p, char direction)
{
    int line = 0;
    if (direction == 'D' || direction == 'U')
        line = 124;
    else
        line = 45;

    if (bitmask[p.row][p.col] == 1)
    {
        if(pic[p.row][p.col] != line)
            pic[p.row][p.col] = 43;
    }
    else
    {
        bitmask[p.row][p.col] = 1;
        pic[p.row][p.col] = line;
    }

    p = nextPosition(p, direction);

    if (bitmask[p.row][p.col] == 1)
    {
        if(pic[p.row][p.col] != line)
            pic[p.row][p.col] = 43;
    }
    else
    {
        bitmask[p.row][p.col] = 1;
        pic[p.row][p.col] = line;
    }

    return p;
}

int main()
{
    int n;
    scanf("%d", &n);

    string cmd;
    cin >> cmd;

    // . -> 46, | -> 124, '-' -> 45, '+' -> 43
    vector<bitset<101>> bitmask(n);
    vector<vector<int>> pic(n, vector<int>(n, 46));

    position p = position(0, 0);

    for (int i = 0; i < cmd.length(); i++)
    {
        if (canGo(p, n, cmd[i]))
        {
            p = drawLine(bitmask, pic, p, cmd[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", pic[i][j]);
        printf("\n");
    }
}