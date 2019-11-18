#include <iostream>
using namespace std;

int solve(int f1, int f2, int n)
{
    if(n == 1)
        return f1 + f2;
    else
    {
        return solve(f2, f1 + f2, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    if(n == 0)
        cout << 0 << endl;
    else if(n==1)
        cout << 1 << endl;
    else
    {
        cout << solve(0, 1, n - 1);
    }
}