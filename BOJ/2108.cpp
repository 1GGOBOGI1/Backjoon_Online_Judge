#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define MAX_NUM 500000
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.second==b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;

    int num[n], sum = 0, input;
    vector<pair<int, int> > cnt;

    for (int i = 0; i < n;i++)
    {
        cin >> input;
        num[i] = input;
        sum += input;
    }
    
    sort(num,num+n);

    for (int i = 0;i<n;i++)
    {
        if(cnt.empty())
        {
            cnt.push_back(make_pair(num[i], 1));
            continue;
        }

        if(cnt.back().first==num[i])
        {
            cnt.back().second++;
        }
        else
        {
            cnt.push_back(make_pair(num[i], 1));
        }
    }

    sort(cnt.begin(), cnt.end(), compare);

    cout<<floor(((double)sum/n)+0.5)<<'\n'<<num[n/2]<<'\n';

    if(cnt[0].second==cnt[1].second)
        cout<<cnt[1].first<<'\n';
    else
        cout<<cnt[0].first<<'\n';

    cout<<num[n-1]-num[0];
}