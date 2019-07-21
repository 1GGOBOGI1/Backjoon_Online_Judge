#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ans(vector<int> set, int set_size, int n)
{
    if (set_size == n)
    {
        for (int i = 0; i < n; i++)
            cout << set[i] << " ";
        cout << "\n";
        return;
    }

    auto set_iter = set.begin();

    vector<int> new_set(n);

    new_set.insert(set_iter, set_iter + set_size);

    for (int i = set_size; i < n; i++)
    {
        vector<int> _set = set;
        new_set.push_back(_set[i]);
        auto _set_iter = _set.begin();
        _set.erase(_set_iter + i);
        new_set.insert(_set.begin(), _set.end());
        ans(_set, set_size + 1, n);
    }
}
int main()
{
    int N;
    cin >> N;

    vector<int> set(N);
    for (int i = 0; i < N; i++)
    {
        set[i] = i + 1;
    }

    ans(set, 0, N);
}