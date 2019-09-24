#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int row, col;

    cin >> row >> col;

    int box[row][col];
    bool pos[row][col];
    long long ans = 0;

    memset(pos, false, sizeof(pos));

    for (int i = 0; i < row; i++)
    {
        int max = -1;
        int maxIndex = -1;
        for (int j = 0; j < col; j++)
        {
            int input;
            cin >> input;
            box[i][j] = input;

            if (max < input)
            {
                max = input;
                maxIndex = j;
            }
        }
        pos[i][maxIndex] = true;
    }

    for (int i = 0; i < col; i++)
    {
        int max = -1;
        int maxIndex = -1;
        for (int j = 0; j < row; j++)
        {
            if (max < box[j][i])
            {
                max = box[j][i];
                maxIndex = j;
            }
        }
        pos[maxIndex][i] = true;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            if (!pos[i][j])
                ans += box[i][j];
    }

    cout << ans;
}