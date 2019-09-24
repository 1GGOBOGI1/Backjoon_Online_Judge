#include <iostream>
//#include <cstdlib>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int input[N + 1] = {0};

    for (int i = 1; i < N + 1; i++)
        cin >> input[i];

    int DP[N + 1][N + 1] = {0};

    // 길이가 1인 것은 팰린드롬
    for (int i = 1; i < N + 1; i++)
        DP[i][i] = 1;

    // 길이가 2인 것은 양옆 비교하여 팰린드롬
    for (int i = 1; i < N; i++)
        if (input[i] == input[i + 1])
            DP[i][i + 1] = 1;

    // 길이가 3 이상
    // y 부터 y + x 까지 팰린드롬인지 확인
    for (int x = 2; x < N; x++)
        for (int y = 1; y <= N - x; y++)
            if (input[y] == input[y + x] && DP[y + 1][y + x - 1] == 1)
                DP[y][y + x] = 1;

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int S, E;
        cin >> S >> E;

        cout << DP[S][E] << "\n";
    }
}