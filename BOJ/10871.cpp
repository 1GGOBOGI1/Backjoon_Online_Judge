#include<iostream>
using namespace std;

int main()
{
    int n, x, input;
    cin >> n >> x;

    for (int i = 0; i < n;i++)
    {
        cin >> input;
        if(input<x)
            cout << input << " ";
    }
}