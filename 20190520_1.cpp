#include <iostream>
using namespace std;

int n;
/*
void ans(int *bills, int *DP, int cnt, int money)
{
    if (cnt == n + 1)
        return;
    for (int i = 1; i < money + 1; i++)
    {
        
        if (i - bills[cnt] >= 0)
            DP[i] += DP[i - bills[cnt]];
    }
    return ans(bills, DP, cnt + 1, money);
}
*/
/*
void Ans(int M, int N)
{
    if (n == 1)
    {
        if (money % bills[n] == 0)
            return 1;
        else
            return 0;
    }

    int t = money / bills[n - 1];
    int count;
    for (int i = 0; i <= t; i++)
        count += Ans(money - bills[n - 1] * i, n - 1);
    return count;
}
*/
int main()
{
    cout << "input number of bills: ";
    cin >> n;

    cout << "input bills: ";
    int bills[n + 1];

    for (int i = 1; i < n + 1; i++)
        cin >> bills[i];

    cout << "input money: ";
    int money;
    cin >> money;

    int DP[money + 1] = {0};
    DP[0] = 1;

    ans(bills, DP, 1, money);
    cout << DP[money];
}