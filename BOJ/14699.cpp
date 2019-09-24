#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph[N + 1];

    int height[N + 1];
    for (int i = 1; i < N + 1; i++)
        cin >> height[i];

    for (int i = 0; i < M; i++)
    {
        int a, b;
        if (height[a] < height[b])
            swap(a, b);

        graph[a].push_back(b);
    }


}