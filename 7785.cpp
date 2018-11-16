#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    const size_t size{26};
    vector<vector<string> > log;
    unsigned int n;
    cin >> n;
    while (n--)
    {
        string name, condition;
        cin >> name >> condition;

        int point = name[0] - 65;
        if (!(0 <= point && point < 91))
        {
            point = point - 32;
        }

        if (condition == "enter")
        {
            log[point].push_back(name);
        }
        else
        {
            vector<string>::iterator iter = find(log[point].begin(), log[point].end(), name);

            if (iter != log[point].end())
            {
                log[point].erase(iter);
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        sort(log[i].begin(), log[i].end());
    }

    for (int i = 0; i < 26; i++)
    {
        while (log[i].size())
        {
            cout << log[i].back() << endl;
            log[i].pop_back();
        }
    }
    return 0;
}