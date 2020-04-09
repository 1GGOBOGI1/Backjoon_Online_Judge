#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct child
{
    int leftChild = -1;
    int rightChild = -1;
};

int makeGraph(vector<child> &node, int V)
{
    int root = (V) * (V + 1) / 2;

    while (V--)
    {
        int n;
        cin >> n;
        cin >> node[n].leftChild >> node[n].rightChild;

        if(node[n].leftChild != -1)
            root -= node[n].leftChild;
        
        if(node[n].rightChild != -1)
            root -= node[n].rightChild;
    }

    return root;
}

int preOrder(vector<child> &node, vector<int> *level, int *column, int v, int lastcolumn, int lastLevel)
{
    int w = lastcolumn;
    level[lastLevel + 1].push_back(v);

    if (node[v].leftChild != -1)
        w = preOrder(node, level, column, node[v].leftChild, lastcolumn, lastLevel + 1);

    w = w + 1;
    column[v] = w;

    if (node[v].rightChild != -1)
        w = preOrder(node, level, column, node[v].rightChild, column[v], lastLevel + 1);

    return w;
}

void ans(vector<child> &node, vector<int> *level, int *column, int *width,int N, int root)
{
    preOrder(node, level, column, root, 0, 0);

    for (int i = 1; i <= N; i++)
    {
        if (level[i].size() != 0)
        {
            int max_column = column[level[i][0]];
            int min_column = column[level[i][0]];

            for (int j = 1; j < level[i].size(); j++)
            {
                if (column[level[i][j]] > max_column)
                    max_column = column[level[i][j]];
                else if (column[level[i][j]] < min_column)
                    min_column = column[level[i][j]];
            }
            width[i] = max_column - min_column + 1;
        }
        else
            width[i] = 0;
    }

    int maxWidthLevel = max_element(width, width + N + 1) - width;

    cout << maxWidthLevel << " " << width[maxWidthLevel];
}

int main()
{
    int N;
    cin >> N;

    vector<child> node(N + 1);
    vector<int> level[N + 1];
    int column[N + 1] = {0};
    int width[N + 1] = {0};

    int root = makeGraph(node, N);
    ans(node, level, column, width,N, root);
}