#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int BFS(vector<int> *node, int V, int removeNode, int root)
{
    queue<int> q;
    bool check[V] = {false};
    int leafNode = 0;

    check[removeNode] = true;
    check[root] = true;
    if (removeNode != root)
        q.push(root);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (node[now].size() == 0)
        {
            leafNode++;
            continue;
        }

        for (int i = 0; i < node[now].size(); i++)
        {
            int next = node[now][i];
            if (!check[next])
            {
                check[next] = true;
                q.push(next);
            }
        }
    }

    return leafNode;
}

int main()
{
    int N;
    cin >> N;

    vector<int> node[N];
    int parent[N];
    int root = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> parent[i];
        if (parent[i] == -1)
        {
            root = i;
            continue;
        }

        node[parent[i]].push_back(i);
    }

    int removeNode;
    cin >> removeNode;

    if (removeNode == root)
    {
        cout << 0;
    }
    else
    {
        node[parent[removeNode]].erase(remove(node[parent[removeNode]].begin(), node[parent[removeNode]].end(), removeNode), node[parent[removeNode]].end());
        cout << BFS(node, N, removeNode, root);
    }
}