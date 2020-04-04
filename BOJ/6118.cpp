#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct dij
{
    int distance = 9999999;
    int prevNode = -1;
    bool check = false;
};

void makeGraph(vector<int> *graph, int E)
{
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void Dijstra(vector<int> *graph, int V)
{
    vector<dij> arr(V + 1);

    arr[1].distance = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push(make_pair(0, 1));

    while (!q.empty())
    {
        int prev = q.top().second;
        q.pop();
        if (!arr[prev].check)
        {
            arr[prev].check = true;

            for (int i = 0; i < graph[prev].size(); i++)
            {
                int next = graph[prev][i];
                if (arr[next].distance > arr[prev].distance + 1)
                {
                    arr[next].distance = arr[prev].distance + 1;
                    arr[next].prevNode = prev;
                    q.push(make_pair(arr[next].distance, next));
                }
            }
        }
    }
    int maxIndex = 1;
    int cnt = 0;
    for (int i = 1; i <= V; i++)
    {

        if (arr[maxIndex].distance == arr[i].distance)
        {
            cnt++;
        }
        if (arr[maxIndex].distance < arr[i].distance)
        {
            maxIndex = i;
            cnt = 1;
        }
    }

    cout << maxIndex << " " << arr[maxIndex].distance << " " << cnt << "\n";
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> graph[N + 1];

    makeGraph(graph, M);
    Dijstra(graph, N);
}