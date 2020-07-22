#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Data
{
    Point point;
    int day;

    Data(Point _point, int _day) : point(_point), day(_day){}
};

int solution(queue<Data> q, vector<vector<int>> &box, int M, int N, int total)
{
    int answer = 0;
    int complete = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty())
    {
        Data now = q.front();
        q.pop();
        complete++;
        if(answer < now.day)
            answer = now.day;

        for (int i = 0; i < 4; i++)
        {
            int next_x = now.point.x + dx[i];
            int next_y = now.point.y + dy[i];

            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M && box[next_x][next_y] == 0)
            {
                q.push(Data(Point(next_x, next_y),now.day+1));
                box[next_x][next_y] = 1;
            }
        }
    }

    return complete == total ? answer : -1;
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    // M = 상자 가로 칸 수 , N = 상자 세로 칸 수

    vector<vector<int> > box(N, vector<int>(M,0));
    queue<Data> q;
    int total = M * N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &box[i][j]);
            if (box[i][j] == 1)
                q.push(Data(Point(i, j),0));
            if(box[i][j] == -1)
                total = total - 1;
        }
    }

    printf("%d", solution(q, box, M, N, total));
}