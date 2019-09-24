#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> groups;
    int N;
    cin >> N;
    while (N--)
    {
        string word;
        string ans = "";
        cin >> word;
        int dic[26] = {0};
        for (int i = 0; i < word.size(); i++)
            dic[word[i] - 97]++;
        for (int i = 0; i < 26; i++)
            if (dic[i] != 0)
            {
                ans.push_back(((char)(i + 97)));
                ans += to_string(dic[i]);
            }
        if (groups.size() == 0)
            groups.push_back(ans);
        else
        {
            vector<string>::iterator iter = find(groups.begin(), groups.end(), ans);
            if (iter == groups.end())
                groups.push_back(ans);
        }
    }
    cout << groups.size();
    return 0;
}