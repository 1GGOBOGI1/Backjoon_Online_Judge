#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int ans = 0;

    vector<string> change = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for (int i = 0; i < input.size(); i++)
    {
        if (i + 1 < input.size())
        {
            string compare2 = input.substr(i, 2);
            string compare3;
            if (i + 2 < input.size())
            {
                compare3 = input.substr(i, 3);
            }
            else
                compare3 = "null";

            if (find(change.begin(), change.end(), compare3) != change.end())
            {
                ans++;
                i += 2;
                continue;
            }
            else if (find(change.begin(), change.end(), compare2) != change.end())
            {
                ans++;
                i++;
                continue;
            }
        }
        ans++;
    }
    cout << ans << endl;
}