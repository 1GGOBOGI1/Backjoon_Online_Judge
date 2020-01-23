#include <iostream>
#include <cstring>
using namespace std;

int D[1001][3][4];

int solve(int n, int day, int l, int a)
{
    if(l >= 2 || a >= 3)
        return 0;
    if(n == day)
        return 1;

    if(D[day][l][a] != -1)
        return D[day][l][a];

    return D[day][l][a] = (solve(n, day + 1, l, 0) + solve(n, day + 1, l + 1, 0) + solve(n, day + 1, l, a + 1)) % 1000000;
}

int main()
{
    int N;
    cin >> N;
    memset(D, -1, sizeof(D));

    cout << solve(N, 0, 0, 0);
}