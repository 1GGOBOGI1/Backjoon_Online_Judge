#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ans[2] = {1, 0}, now = 1;
    string input;
    getline(cin, input);
    for (int i = 1; i < input.size(); i++)
    {
        if (input[i - 1] == input[i])
            continue;
        ans[now % 2]++;
        now++;
    }

    if (ans[0] < ans[1])
        cout << ans[0];
    else
        cout << ans[1];
}