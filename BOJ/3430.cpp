#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int start, end;
    Point(int _start, int _end) : start(_start), end(_end) {}
};

struct Disaster
{
    vector<int> calendar, nextGroup, drinkingDay;
    vector<Point> group;

    Disaster(int n, int m) : calendar(n + 1, 0), nextGroup(m + 1, 0) {}


};

int solution(int n, int m)
{
    Disaster disaster(n, m);

    for (int i = 1; i <= m;i++)
    {
        int input;
        scanf("%d", &input);

        if(input == 0)
        {
            
            continue;
        }
    }
}

int main()
{
    int Z;
    scanf("%d", &Z);

    while (Z--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
    }
}