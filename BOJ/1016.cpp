#include <iostream>
using namespace std;

long long int calc(long long int a, long long b)
{
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    else if (b % 2 == 0)
    {
        long long int tmp = calc(a, b / 2);
        return tmp * tmp;
    }
    else
        return a * calc(a, b - 1);
}

int main()
{
    long long int min, max;
    cin >> min >> max;

    bool check[(max - min + 1) + 1] = {1};
    long long int ans = max - min + 1;

    for (int i = min; i < max - min + 1; i++)
        cout << check[i];

    for (long long int i = min; i*i < max - min + 2; i++)
    {
        long long now = calc(i, i);
        cout << "now = " << now << endl;
        for (long long int j = now; j < max - min + 2; j+=now)
        {
            if (check[j]!=0 && check[j] % j == 0)
            {
                check[j] = true;
                ans--;
            }
        }
    }

    cout << ans;
}