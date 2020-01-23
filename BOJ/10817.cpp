#include<iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a >= b)
    {
        if (b >= c) //a >= b >= c
            cout << b;
        else
        {
            if(a>=c) // a >= c >= b
                cout << c;
            else // c >= a >= b
                cout << a;
        }
    }
    else
    {
        if(a >= c) // b >= a >= c
            cout << a;
        else
        {
            if(b>=c) // b >= c >= a
                cout << c;
            else
                cout << b;
        }
    }
}