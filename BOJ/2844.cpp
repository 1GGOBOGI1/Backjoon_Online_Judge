#include <iostream>
using namespace std;

int main()
{
    int h, m;
    cin >> h >> m;

    if(m>=45)
        m = m - 45;
    else
    {
        h = h - 1;
        m = m + 60 - 45;
    }

    cout << ((h < 0) ? 24 + h : h) << " " << m;
}