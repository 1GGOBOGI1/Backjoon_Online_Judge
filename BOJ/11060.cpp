#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> m(N);

    for(int i = 0; i < N; i++)
        scanf("%d", &m[i]);

    vector<int> DP(N,INF);

    DP[0] = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 1; j < m[i]+1; j++)
        {
            if(i+j < N)
            {
                DP[i+j] = min(DP[i+j],DP[i]+1);
            }
        }
    }
    
    printf("%d", DP[N-1] == INF? -1:DP[N-1]);
}   