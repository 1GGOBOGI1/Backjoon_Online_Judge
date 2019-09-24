#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int c[N + 2][N + 2];
    for (int i = 0; i < N + 1; i++)
    {
        c[i][0] = 1;
        c[i][i] = 1;
    }

    for (int i = 2; i < N + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j])%10007;
        }
    }
    cout << c[N][K]<< endl;
}