#include <iostream>
#include <vector>
#include <string>
using namespace std;

void quadTree(vector<vector<int>> &pic, int size, int x, int y, int original_size)
{

    int standard = pic[x][y];

    if (size == 1)
    {
        cout << pic[x][y];
        return;
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (pic[x + i][y + j] != standard)
            {
                cout << "(";
                quadTree(pic, size / 2, x, y, original_size);
                quadTree(pic, size / 2, x, y + (size / 2), original_size);
                quadTree(pic, size / 2, x + (size / 2), y, original_size);
                quadTree(pic, size / 2, x + (size / 2), y + (size / 2), original_size);
                cout << ")";
                return;
            }

    cout << standard;
    return;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> pic(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < N; j++)
            pic[i][j] = int(input[j] - 48);
    }

    quadTree(pic, N, 0, 0,N);
}