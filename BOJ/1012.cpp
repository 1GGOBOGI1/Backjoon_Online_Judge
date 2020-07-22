#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct position
{
    int x, y;
    position(int _x, int _y): x(_x), y(_y){}
};

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int M, N, K;
        scanf("%d %d %d", &M, &N, &K);

        vector<vector<int>> map(M, vector<int>(N, 0));

        for (int i = 0; i < K; i++)
        {
            int X, Y;
            scanf("%d %d", &X, &Y);

            map[X][Y] = 1;
        }

        int ans = 0;

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if(map[i][j] == 1)
                {
                    queue<position> q;
                    map[i][j] = 0;
                    q.push(position(i, j));

                    while(!q.empty())
                    {
                        int x = q.front().x;
                        int y = q.front().y;
                        q.pop();

                        if(x-1 >= 0 && map[x-1][y] == 1)
                        {
                            map[x - 1][y] = 0;
                            q.push(position(x - 1, y));
                        }
                        if(y-1 >= 0 && map[x][y-1] == 1)
                        {
                            map[x][y - 1] = 0;
                            q.push(position(x, y - 1));
                        }
                        if(x+1 < M && map[x+1][y] == 1)
                        {
                            map[x + 1][y] = 0;
                            q.push(position(x + 1, y));
                        }
                        if (y + 1 < N && map[x][y+1] == 1)
                        {
                            map[x][y + 1] = 0;
                            q.push(position(x, y + 1));
                        }
                    }
                    ans++;
                }
            }

        printf("%d\n", ans);
    }
}