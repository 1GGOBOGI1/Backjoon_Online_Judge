#include <iostream>
#include <vector>
using namespace std;

void makeGraph(vector<int> *g, int V)
{
    int exist = 0;
    for (int i = 1; i <= V;i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cin >> exist;
            if(exist)
            {
                g[i].push_back(j);
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int> graph[N + 1];
}