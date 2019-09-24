#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph[3];
    vector<pair<int, int>> graph_cnt;

    for (int i = 0; i < 3; i++)
        graph_cnt.push_back(make_pair(0, 0));

    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        char a;
        int b;
        cin >> a >> b;

        if (a == '*')
        {
            graph[0].push_back(b);
            if (b < 0)
                graph_cnt[0].first++;
            else
                graph_cnt[0].second++;
        }

        else if (a == '/')
        {
            graph[1].push_back(b);
            if (b < 0)
                graph_cnt[1].first++;
            else
                graph_cnt[1].second++;
        }
        else
        {
            graph[0].push_back(b);
            if (b < 0)
                graph_cnt[2].first++;
            else
                graph_cnt[2].second++;
        }

        if (graph[0].size() != 0)
            ans++;

        ans = ans + (2 * graph_cnt[0].first * graph_cnt[1].first + 2 * graph_cnt[0].second * graph_cnt[1].second);

        
    }
}