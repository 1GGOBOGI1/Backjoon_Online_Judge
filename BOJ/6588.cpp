#include <iostream>
#include <vector>
using namespace std;

void setIsPrime(vector<bool> &isPrime)
{
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i < isPrime.size(); i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = i * 2; j < isPrime.size(); j += i)
            isPrime[j] = false;
    }
}

void solution(vector<bool> &isPrime, int n)
{
    for (int i = n - 1; i > 2; i--)
        if (isPrime[i] && i % 2 == 1 && (n - i) % 2 == 1 && isPrime[n - i])
        {
            printf("%d = %d + %d\n", n, n - i,i);
            return;
        }

    printf("Goldbach's conjecture is wrong.\n");
    return;
}

int main()
{
    vector<bool> isPrime(1000000 + 1, true);
    setIsPrime(isPrime);

    int input;

    while (true)
    {
        scanf("%d", &input);
        if (input == 0)
            break;

        solution(isPrime, input);
    }
}