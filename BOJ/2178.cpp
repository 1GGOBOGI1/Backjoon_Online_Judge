#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Data
{
    Point point;
    long long distance = 0;

    Data(Point _point, int _distance) : point(_point), distance(_distance) {}
};

long long solution(vector<string> puzzle, int N, int M)
{
    int answer = -1;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    queue<Data> q;
    bool check[N][M] = {false};
    memset(check, false, sizeof(check));

    q.push(Data(Point(0, 0), 1));
    check[0][0] = true;

    while (!q.empty())
    {
        Data now = q.front();
        q.pop();

        if (now.point.x == N - 1 && now.point.y == M - 1)
        {
            answer = now.distance;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_x = now.point.x + dx[i];
            int next_y = now.point.y + dy[i];

            if(0 <= next_x && next_x < N && 0 <= next_y && next_y < M && puzzle[next_x][next_y] == '1' && !check[next_x][next_y])
            {
                q.push(Data(Point(next_x, next_y), now.distance + 1));
                check[next_x][next_y] = true;
            }
        }
    }

    return answer;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<string> puzzle(N + 1);

    for (int i = 0; i < N; i++)
        cin >> puzzle[i];

    printf("%lld", solution(puzzle, N, M));
}