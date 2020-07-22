#include <iostream>
using namespace std;

long long solution(int n,int m,int k)
{
    long long numOfTwo = 0, numOfFive = 0;

    for (long long i = 2; i <= n; i*=2)
        numOfTwo += n / i;

    for (long long i = 2; i <= m;i*= 2)
        numOfTwo -= m / i;

    for (long long i = 2; i <= k;i*=2)
        numOfTwo -= k / i;

    for (long long i = 5; i <= n;i*=5)
        numOfFive += n / i;

    for (long long i = 5; i <= m;i*=5)
        numOfFive -= m / i;

    for (long long i = 5; i <= k;i*=5)
        numOfFive -= k / i;

    return min(numOfTwo, numOfFive);
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d", solution(n, m,n-m));
}