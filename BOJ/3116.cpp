#include <iostream>
#include <set>
using namespace std;

struct Point
{
    int x, y;
};

pair<int,int> moveBacteria(int x, int y, int d)
{
    switch(d)
    {
        case 1:
            x = x - 1;
            y = y + 1;
            break;
        case 2:
            y = y + 1;
            break;
        case 3:
            x = x + 1;
            y = y + 1;
            break;
        case 8:
            x = x - 1;
            break;
        case 4:
            x = x + 1;
            break;
        case 7:
            x = x - 1;
            y = y - 1;
            break;
        case 6:
            y = y - 1;
            break;
        case 5:
            x = x + 1;
            y = y - 1;
            break;
    }
    return make_pair(x, y);
}

int main()
{
    int N;
    scanf("%d", &N);

    Point bacteria[N];
    int direction[N];

    for (int i = 0; i < N; i ++)
        scanf("%d %d %d", &bacteria[i].x, &bacteria[i].y, &direction[i]);

    set<pair<int, int>> map;

    
}