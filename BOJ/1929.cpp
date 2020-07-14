#include <iostream>
#include <vector>
using namespace std;

void solution(int M, int N)
{
    vector<bool> isPrime(N+1, true);
    isPrime[1] = false;

    for (int i = 2; i <= N; i++)
    {
        if(!isPrime[i])
            continue;

        for (int j = i * 2; j <= N; j+=i)
            isPrime[j] = false;
    }

    for (int i = M; i < isPrime.size();i++)
        if(isPrime[i])
            printf("%d\n", i);
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);

    solution(M, N);
}