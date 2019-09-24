#include <iostream>
#include<vector>
using namespace std;

long long int ans = 0;
int N;

int main()
{
    cin >> N;

    int arr[N][N] = {0};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N ; j++)
            cin >> arr[i][j];
    }

    long long int DP[N][N] = {1,0};

    for (int x = 0; x < N;x++)
    {
        for (int y = 0; y < N;y++)
        {
            if((x==N-1)&&(y==N-1))
                continue;
            if(x+arr[x][y]<N)
                DP[x + arr[x][y]][y] += DP[x][y];
            if(y+arr[x][y]<N)
                DP[x][y + arr[x][y]] += DP[x][y];
        }
    }

    cout << DP[N-1][N-1];
}