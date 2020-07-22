#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if(b==0)
        return a;

    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    int g = GCD(a, b);

    return g * (a / g) * (b / g);
}



int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", LCM(a, b));
    }
}