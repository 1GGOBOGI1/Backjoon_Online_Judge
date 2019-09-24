#include <iostream>
using namespace std;

int str = 1;

int ans(int num)
{
    str++;

    if (num >= 1)
        ans(num - 1);

    if (num >= 0.5)
        ans(num - 0.5);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        str = 1;
        ans(n - 1);
        cout << str;
    }
}