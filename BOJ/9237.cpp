#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    cin >> N;
    vector<int> tree(N + 1);

    for (int i = 0; i < N; i++)
        cin >> tree[i];

    sort(tree.begin(), tree.end(), cmp);

    int invite = 0;
    for (int i = 0; i < N; i++)
    {
        if (invite < (i + 1) + tree[i])
            invite = (i + 1) + tree[i];
    }

    cout << invite+1;
}