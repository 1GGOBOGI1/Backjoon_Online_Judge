#include<iostream>
using namespace std;

long long int calc(long long int a,long long int b,long long c)
{
    if(b==0)
        return 1;
    else if(b==1)
        return a%c;
    else if(b%2 == 0)
    {
        long long int tmp = calc(a, b / 2)%c;
        return tmp * tmp;
    }
    else
        return a * calc(a, b - 1)%c;
}

int main()
{
    int A, B, C;
    cin >> A >> B>>C;

    cout << calc(A, B,C);
}