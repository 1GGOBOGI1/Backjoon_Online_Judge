#include <iostream>
using namespace std;

int solve(int n)
{
    if(n == 1 || n == 0)
        return 1;
    return n * solve(n - 1);
}

int main()
{
    int N;
    cin >> N;
    cout << solve(N);
}