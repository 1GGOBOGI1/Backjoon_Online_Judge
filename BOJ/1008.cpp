#include <iostream>
using namespace std;

int main()
{
    long double a, b;
    cin >> a >> b;

    cout << fixed;
    cout.precision(9);
    cout << double(a) / b;
}