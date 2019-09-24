#include<iostream>
using namespace std;

int main()
{
    int th1, th2;
    cin >> th1 >> th2;

    if (th2 != 0 && th1 % 30 == 0)
    {
        cout << "X";
        return 0;
    }
    else
    {
        double remain = th1 - (th1 / 30) * 30;

        double x = ((double)th2 / 6) * 0.5;

        if (remain == x)
        {
            cout << "O";
            return 0;
        }
        else
            cout << "X";
    }
}