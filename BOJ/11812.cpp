#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long N, x, y, distance;
    int K, Q;

    scanf("%lld %d %d", &N, &K, &Q);
    while (Q--)
    {
        distance = 0;
        scanf("%lld %lld", &x, &y);

        if (K == 1)
        {
            x > y ? distance = x - y : distance = y - x;
        }
        else
        {
            while (x != y)
            {
                x > y ? x = (x - 2) / K + 1 : y = (y - 2) / K + 1;
                distance++;
            }
        }
        printf("%lld\n", distance);
    }
}