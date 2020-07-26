#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long A, B, C;

    scanf("%lld %lld %lld", &A, &B, &C);

    if(B >= C)
    {
        printf("%d",-1);
        return 0;
    }

    long long ans = A / (C-B);

    printf("%lld", ++ans);
}