#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include<string.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int ans = pow(2, N *M);
    
    

    int nemo[(N * M) + 1];
    int c[(N * M) + 2][(N * M) + 2];
    memset(c, 0, sizeof(c));

    for (int i = 0; i < (N * M) + 1; i++)
    {
        c[i][0] = 1;
        c[i][i] = 1;
    }

    for (int i = 2; i < (N * M) + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
        }
    }

    for (int i = 0; i < (N * M) + 1; i++)
    {
        for (int j = 0; j < (N * M) + 1; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }

    nemo[N * M] = 1;

    if (N < 2 || M < 2)
    {
        cout << pow(2, N * M);
        return 0;
    }

    for (int i = 4; i <N * M; i++)
    {
        cout << "i = " << i << endl;
        if (i % 4 == 0)
        {
            int x = N - 1, y = M - 1;
            nemo[i] = x * y;
        }
        else
        {
            
            nemo[i] = nemo[4 * (i / 4)] * c[N * M - 4 * (i / 4)][i - 4 * (i / 4)];

            for (int j = 4 * (j / 4); j >= 4;j -=4)
                nemo[i] += nemo[j];
        }
        ans -= nemo[i];
        cout << "nemo[i] = " << nemo[i] << endl;
        cout << "ans =" << ans << endl;
    }
    cout << ans-1;
}