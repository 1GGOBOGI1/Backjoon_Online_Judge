#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;


int main()
{
    int M;
    scanf("%d", &M);

    int color[M];
    int all = 0;

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &color[i]);
        all += color[i];
    }

    int K;
    scanf("%d", &K);

    vector<double> p(M, 1);
    double ans = 0;
    for (int i = 0; i < M; i++)
    {
        if(color[i] < K)
        {
            continue;
        }

        for (int j = 0; j < K; j++)
        {
            p[i] *= (double)(color[i] - j)/ (all-j);
        }
        ans += p[i];
    }
    printf("%.18lf", ans);
}