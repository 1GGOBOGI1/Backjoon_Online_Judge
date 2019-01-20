#include <iostream>
#include <array>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int DNA[M][4] = {0}, ans = 0;
    char dna[4] = {'A', 'C', 'G', 'T'};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char input;
            cin >> input;
            switch (input)
            {
            case 'A':
                DNA[j][0]++;
                break;
            case 'C':
                DNA[j][1]++;
                break;
            case 'G':
                DNA[j][2]++;
                break;
            case 'T':
                DNA[j][3]++;
                break;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        int maxIndex = 0, max = DNA[i][0];
        for (int j = 0; j < 4; j++)
        {
            if (max < DNA[i][j])
            {
                maxIndex = j;
                max = DNA[i][j];
            }
        }
        for (int j = 0; j < 4; j++)
        {
            if (j == maxIndex)
                continue;
            ans += DNA[i][j];
        }
        cout << dna[maxIndex];
    }
    cout << "\n"
         << ans;
}