#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if(num < 2)
        return false;

    for (int i = 2; i * i <= num;i++)
        if(num % i == 0)
            return false;

    return true;
}

int solution(int N)
{
    int answer = 0;
    while(N--)
    {
        int input;
        scanf("%d", &input);

        if(isPrime(input))
            answer++;
    }

    return answer;
}

int main()
{
    int N;
    scanf("%d", &N);

    printf("%d", solution(N));
}