#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int ans[3] = {0};
int paper[2500][2500];

void check(int x, int y, int size)
{
    int base = paper[x][y];
    bool _check = true;
    if (size == 1)
    {
        ans[base + 1]++;
        return;
    }
    for (int _x = x; _x < x + size; _x++)
        for (int _y = y; _y < y + size; _y++)
            if (paper[_x][_y] != base)
            {
                _check = false;
                break;
            }
    if (_check)
    {
        ans[base + 1]++;
        return;
    }
    else
    {
        for (int _x = 0; _x < 3; _x++)
            for (int _y = 0; _y < 3; _y++)
                check(x + (size / 3) * _x, y + (size / 3) * _y, size / 3);
        return;
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &paper[i][j]);
    check(0, 0, N);
    printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
}