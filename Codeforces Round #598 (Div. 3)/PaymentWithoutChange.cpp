#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;

    int a, b, n, S;

    while(q--)
    {
        cin >> a >> b >> n >> S;

        int x = S / n;
        int y = S - n * x;

        if(x > a)
        {
            y = y + n * (x - a);
            x = a;
        }

        if(x <= a && y <= b)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
        }
    }
}