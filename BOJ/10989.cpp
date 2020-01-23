#include <iostream>
#include <cstring>
#define MAX_NUM 10000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int cnt[MAX_NUM+1];

    memset(cnt, 0, sizeof(cnt));

    int input;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> input;
        cnt[input]++;
    }

    for (int i = 0; i < MAX_NUM + 1;i++)
    {
        for (int j = 0; j < cnt[i];j++)
            cout << i << '\n';
    }
}