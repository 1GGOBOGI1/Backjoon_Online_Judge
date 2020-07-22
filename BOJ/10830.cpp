#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<long long>> &A, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%lld ", A[i][j]);
        printf("\n");
    }
}

vector<vector<long long>> multiplication(vector<vector<long long >> &A, vector<vector<long long>> &B, int N)
{
    vector<vector<long long>> C(N, vector<long long>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
                C[i][j] += ((A[i][k]%1000) * (B[k][j]%1000))%1000;
            C[i][j] %= 1000;
        }

    return C;
}

vector<vector<long long>> calc(vector<vector<long long>> &A, int B, int N)
{
    if(B == 0)
    {
        vector<vector<long long>> tmp(N, vector<long long>(N, 0));
        for (int i = 0; i < N;i++)
            for (int j = 0; j < N; j++)
                if(i == j)
                    tmp[i][j] = 1;

        // printMatrix(tmp,N);
        return tmp;
    }
    else if (B % 2 == 0)
    {
        vector<vector<long long>> tmp = calc(A, B / 2, N);
        // vector<vector<long long>> test = multiplication(tmp, tmp, N);
        // printMatrix(test, N);
        return multiplication(tmp, tmp, N);
    }
    else
    {
        vector<vector<long long>> tmp = calc(A, B - 1, N);
        // vector<vector<long long>> test = multiplication(A, tmp, N);
        // printMatrix(test, N);
        return multiplication(A, tmp, N);
    }
}

int main()
{
    int N, B;
    scanf("%d %d", &N, &B);

    vector<vector<long long>> A(N, vector<long long>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%lld", &A[i][j]);

    vector<vector<long long>> ans = calc(A, B, N);

    printMatrix(ans, N);
}