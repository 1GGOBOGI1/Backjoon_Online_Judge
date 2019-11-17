#include <iostream>
#include <algorithm>
#define INF 999999
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int d[n + 1][n + 1];

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            d[i][j] = INF;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 예제 입력에 출발지와 목적지는 같은데 cost가 다른 것도 있음
        // cost 작은 걸 저장해야 함
        d[a][b] = min(d[a][b], c);
    }

    // i -> k -> j
    for (int k = 1; k < n + 1; k++)
    {
        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < n + 1; j++)
            {
                // 시작 도시와 도착 도시가 같은 경우는 없음
                if (i == j)
                    continue;
                // i -> k 로 가는 경로나 k -> j로 가는 경로가 없을 경우
                // i -> k -> j 계산 못함
                if (d[i][k] != INF && d[k][j] != INF)
                    d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
            if (d[i][j] == INF)
                cout << 0 << " ";
            else
            {
                cout << d[i][j] << " ";
            }

        cout << "\n";
    }
}