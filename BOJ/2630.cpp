#include <iostream>
#include <vector>
using namespace std;

int color[2] = {0, 0};

void make_paper(vector<vector<int>> &paper, int size, int x, int y)
{
    int standard = paper[x][y];

    if (size == 1)
    {
        color[standard]++;
        return;
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (paper[x + i][y + j] != standard)
            {
                make_paper(paper, size / 2, x, y);
                make_paper(paper, size / 2, x + (size / 2), y);
                make_paper(paper, size / 2, x, y + (size / 2));
                make_paper(paper, size / 2, x + (size / 2), y + (size / 2));
                return;
            }

    color[standard]++;
    return;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> paper(N,vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    make_paper(paper, N, 0, 0);
    cout << color[0] << "\n"
         << color[1] << endl;
}