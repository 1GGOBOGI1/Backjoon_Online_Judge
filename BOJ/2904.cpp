#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX_SIZE 1000001
using namespace std;

void checkPrime(bool *isPrime, int totalSize, vector<int> &prime)
{
    for (int i = 2; i < totalSize; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            isPrime[i] = false;
            for (long long j = i * 2; j < totalSize; j += i)
                isPrime[j] = false;
        }
    }
}

void solution(vector<int> &input, vector<int> &prime)
{
    int N = input.size();

    vector<vector<int>> arguments(input.size(), vector<int>(prime.size(), 0));
    vector<int> usedPrimeCount(prime.size(), 0);
    for (int i = 0; i < input.size(); i++)
    {
        int now = input[i];

        for (int j = 0; (now != 1) && j < prime.size(); j++)
        {
            while ((now != 1) && !(now % prime[j]))
            {
                usedPrimeCount[j]++;
                arguments[i][j]++;

                now /= prime[j];
            }
        }
    }

    int score = 1, tryCount = 0;

    for (int j = 0; j < prime.size(); j++)
    {
        int power = usedPrimeCount[j] / N;

        if (power > 0)
        {
            score *= (int)pow(prime[j], power);

            for (int i = 0; i < input.size(); i++)
            {
                if (power > arguments[i][j])
                {
                    tryCount += power - arguments[i][j];
                }
            }
        }
    }

    printf("%d %d", score, tryCount);
}

int main()
{
    bool isPrime[MAX_SIZE];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;

    vector<int> prime;
    checkPrime(isPrime, MAX_SIZE, prime);

    int N;
    scanf("%d", &N);

    vector<int> input(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &input[i]);

    solution(input, prime);
}