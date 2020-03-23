#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> chips(k + 1);
    vector<pair<int, int>> visitPosition(k + 1);

    for (int i = 1; i <= k;i++)
    {
        int sx, sy;
        cin >> sx >> sy;
        chips[i].first = sx;
        chips[i].second = sy;
    }

    for (int i = 1; i <= k;i++)
    {
        int fx, fy;
        cin >> fx >> fy;
        visitPosition[i].first = fx;
        visitPosition[i].second = fy;
    }

    
}