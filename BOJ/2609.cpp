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

    return a * b / g;
}

void solution(int a, int b)
{
    printf("%d\n%d", GCD(a, b), LCM(a, b));
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    solution(a, b);
}