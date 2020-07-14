#include <iostream>
using namespace std;

int solution(int N)
{
    int a = 0, b = 0;

    for (int i = 2; i <= N; i++)
    {
        int now = i;
        while(now % 2 == 0)
        {
            a++;
            now /= 2;
        }

        while (now % 5 == 0)
        {
            b++;
            now /= 5;
        }
    }

    return min(a, b);
}

int main()
{
    int N;
    scanf("%d", &N);

    printf("%d", solution(N));
}