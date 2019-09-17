#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int dp[n][n] = {
    999999,
};
int main()
{
    //cin.tie(NULL); ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    vector<pair<char, int>> v;
    vector<int> open;
    char ch;

    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        if (ch == '(')
        {
            open.push_back(i);
            v.push_back(make_pair(ch, 0));
        }
        else if (ch == ')')
        {
            //close.push_back(i);
            int position = open.back();
            v.push_back(make_pair(ch, position));
            v[position].second = i;
            open.pop_back();
        }
        else
        {
            v.push_back(make_pair(ch, 0));
        }
    }
    // for(int i=0;i<n;i++){
    //     cout << v[i].first <<" "<<v[i].second<<endl;
    // }
    int from, to, dir, pos, cnt;

    for (int i = 0; i < q; i++)
    {
        cnt = 0;
        cin >> from >> to;
        from--;
        to--;
        if (from > to)
        {
            int tmp = to;
            to = from;
            from = tmp;
        }
        pos = from;
        while (pos != to)
        {
            while (pos < to)
            {
                if (v[pos].first == '(')
                {
                    if (v[pos].second == pos + 1 || abs(v[pos].second - to) >= (to - pos))
                    {
                        cnt++;
                        pos++;
                        //dp[pos-1][pos]
                    }
                    else
                    {
                        cnt += 2;
                        pos = v[pos].second;
                    }
                }
                // else if(v[pos].first == '.'){
                //     cnt++;
                //     pos++;
                // }
                else
                {
                    cnt++;
                    pos++;
                }
                //cout << pos <<" ";
            }
            if (pos != to)
            {
                if (v[pos].first == ')')
                {
                    if (v[pos].second == pos + 1 || abs(to - v[pos].second) >= abs(to - pos))
                    {
                        cnt++;
                        pos--;
                    }
                    else
                    {
                        cnt += 2;
                        pos = v[pos].second;
                    }
                }
                // else if(v[pos].first == '.'){
                //     cnt++;
                //     pos--;
                // }
                else
                {
                    cnt++;
                    pos--;
                }
                //cout << pos <<" ";
            }
        }

        cout << cnt;
    }

    return 0;
}