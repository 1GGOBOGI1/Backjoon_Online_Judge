#include <iostream>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >>M;

    int A[N][M];

    for (int n = 0; n < N; n++)
        for (int m = 0; m < M;m++)
            cin >> A[n][m];

    cin >> M >> K;

    int B[M][K];

    for (int m = 0; m < M;m++)
        for (int k = 0; k < K;k++)
            cin >> B[m][k];

    
}