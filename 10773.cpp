#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> list;

    int K;
    cin >> K;

    int tmp;
    for (int i = 0; i < K; i++)
    {
        cin >> tmp;
        if (tmp != 0)
            list.push(tmp);
        else
            list.pop();
    }

    int ans = 0;
    int lsit_size = list.size();
    for (int i = 0; i < lsit_size; i++, list.pop())
        ans += list.top();

    cout << ans;
}