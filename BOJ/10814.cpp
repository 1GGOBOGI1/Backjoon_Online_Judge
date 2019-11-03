#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int N;
    int cnt[201];

    memset(cnt, 0, sizeof(cnt));

    cin >> N;

    vector<pair<int, string> >input;
    vector<pair<int, string> >ans(N);

    for (int i = 0;i<N;i++)
    {
        pair<int, string> tmp;
        cin >> tmp.first >> tmp.second;
        cnt[tmp.first]++;
        input.push_back(tmp);
    }

    for (int i = 2; i < 201;i++)
    {
        cnt[i] = cnt[i] + cnt[i - 1];
    }

    for (int i = N-1; i >= 0;i--)
    {
        int age = input[i].first;
        cnt[age]--;

        ans[cnt[age]] = input[i];
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
}