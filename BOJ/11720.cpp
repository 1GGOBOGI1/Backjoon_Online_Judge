#include <iostream>
using namespace std;

int main()
{
    int n,sum = 0;
    cin >> n;
    char *num;
    num = new char[n];

    cin.get();
    for (int i = 0; i < n; i++)
        num[i] = cin.get();
    for (int i = 0; i < n; i++)
        sum += num[i] - 48;

    cout << sum;
}