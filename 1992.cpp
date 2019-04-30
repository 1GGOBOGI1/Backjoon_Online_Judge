#include <iostream>
#include <cmath>
#include <vector>
#include <cmath>
using namespace std;

int img[64][64] = {0};
void zip(int x, int y, int size)
{
    cout << "(";
    if (size == 1)
    {
        cout << img[x][y];
        return;
    }
    else
    {
        int base = img[x][y];
        bool check = true;
        for (int i = 0; i < x + size; i++)
            for (int j = 0; j < y + size; j++)
                if (img[i][j] != base)
                {
                    check = false;
                }
        if (!check)
        {
            zip(x, y, size / 2);
            zip(x + size / 2, y, size / 2);
            zip(x + size / 2, y, size / 2);
            zip(x + size / 2, y + size / 2, size / 2);
        }
        else
        {
            cout << base;
            return;
        }
    }
    cout << ")";
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &img[i][j]);
    zip(0, 0, N);
}