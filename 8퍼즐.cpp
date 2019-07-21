#include <iostream>
#include <vector>
using namespace std;

struct node
{
    vector<int> arr[3][3] state;
    vector<int>::iterator parent;
    vector<int>::iterator action;
};

void ans()
{
}

int main()
{
    int arr[3][3] = {0};

    node tmp;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> node.state[i][j];
    }
}