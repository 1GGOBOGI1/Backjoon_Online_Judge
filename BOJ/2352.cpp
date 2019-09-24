#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> port(n);
    pair<int, int> min, max;

    min.first = 0, min.second = 0, max.first = n + 1, max.second = n + 1;

    for (int i = 0; i < n; i++)
        cin >> port[i];

    while (port.size())
    {
        
    }
}