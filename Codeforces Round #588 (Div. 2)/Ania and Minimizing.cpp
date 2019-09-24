#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int n, k;
    string S;
    cin >> n >> k;
    cin.ignore(32767, '\n');
    getline(cin, S);

    if (k == 0)
    {
        cout << S;
        return 0;
    }

    if (n == 1)
    {
        if (k > 0)
            cout << 0;
        else
            cout << S;
        return 0;
    }

    if (S[0] != '1')
    {
        S[0] = '1';
        k--;
    }

    for (int i = 1; i < n && k > 0; i++)
    {
        if (S[i] == '0')
            continue;

        S[i] = '0';
        k--;
    }

    for (int i = 0; i < n; i++)
        cout << S[i];
}