#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<string> ans;
    vector<string> n(N);
    vector<string> m(M);

    for (int i = 0; i < N; i++)
        cin >> n[i];

    for (int i = 0; i < M; i++)
        cin >> m[i];

    sort(m.begin(), m.end());
    sort(n.begin(), n.end());

    if (N > M)
    {
        for (int i = 0; i < M; i++)
            if (binary_search(n.begin(), n.end(), m[i]))
                ans.push_back(m[i]);
    }
    else
    {
        for (int i = 0; i < N; i++)
            if (binary_search(m.begin(), m.end(), n[i]))
                ans.push_back(n[i]);
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}