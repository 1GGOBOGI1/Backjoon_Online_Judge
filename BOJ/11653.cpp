#include <iostream>
#include <queue>
using namespace std;

void solution(int N)
{
    queue<int> ans;
    for (int i = 2; i * i <= N;i++)
    {
        while(N%i == 0)
        {
            ans.push(i);
            N /= i;
        }
    }

    if(N > 1)
        ans.push(N);

    while(!ans.empty())
    {
        printf("%d\n", ans.front());
        ans.pop();
    }
    return;
}

int main()
{
    int N;
    scanf("%d", &N);

    solution(N);
}