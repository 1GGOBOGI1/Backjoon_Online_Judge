#include <iostream>
using namespace std;

long long solve(int A, int B, int C)
{
    if(B == 1)
        return A % C;
    else if (B == 0)
        return 1;

    if(B%2)
        return ((((solve(A, B / 2, C) % C) * (solve(A, B / 2, C) % C)) % C) * (A % C)) % C;
    else
    {
        return ((solve(A, B / 2, C) % C) * (solve(A, B / 2, C) % C)) % C;
    }
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    // (A^B)%C
    cout << solve(A, B, C);
}