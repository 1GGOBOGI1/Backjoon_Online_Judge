#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if(b == 0)
        return a;

    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    int g = GCD(a, b);

    return g * (a / g) * (b / g);
}

void solution(int a1, int b1, int a2, int b2)
{
    // n / m
    int m = LCM(b1, b2);
    int n = a1 * (m / b1) + a2 * (m / b2);

    int divider = GCD(m, n);

    printf("%d %d", n / divider, m / divider);
}

int main()
{
    int a1, a2, b1, b2;

    scanf("%d %d\n%d %d", &a1, &b1, &a2, &b2);

    solution(a1, b1, a2, b2);
}