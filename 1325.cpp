#include <iostream>
#include <vector>
using namespace std;

void find_node(vector<int> &_node, vector<vector<int> > node, int *check);

int num = 0;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int> > node(N+1);

    int max = -1;
    int ans[N + 1] = {0};

    for (int i = 0; i < M;i++)
    {
        int a, b;
        cin >> a >> b;
        node[b].push_back(a);
    }

    for (int i = 1; i < N+1;i++)
    {
        int check[N + 1] = {0};
        num = 0;
        find_node(node[i], node,check);
        ans[i] = num;
        if(max<num)
            max = num;
    }
    for (int i = 1; i < N + 1;i++)
    {
        if(ans[i]==max)
            cout << i << " ";
    }
}

void find_node(vector<int>&_node,vector<vector<int> > node,int* check)
{
    for(int item:_node)
    {
        if(check[item]==0)
        {
            check[item] = 1;
            num++;
            find_node(node[item], node,check);
 
        }
        else
            continue;
    }
}

