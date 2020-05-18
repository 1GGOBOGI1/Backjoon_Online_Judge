#include <iostream>
#include <queue>
using namespace std;

int solution(int N, int K)
{
    int answer = 0;
    bool check[100001] = {false};

    queue<pair<int, int>> q;

    q.push(make_pair(N, 0));

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();

        if (front.first == K)
        {
            answer = front.second;
            break;
        }

        if (front.first - 1 >= 0 && !check[front.first - 1])
        {
            check[front.first - 1] = true;
            q.push(make_pair(front.first - 1, front.second + 1));
        }

        if (front.first + 1 <= 100000 && !check[front.first + 1])
        {
            check[front.first + 1] = true;
            q.push(make_pair(front.first + 1, front.second + 1));
        }

        if (front.first * 2 <= 100000 && !check[front.first * 2])
        {
            check[front.first * 2] = true;
            q.push(make_pair(front.first * 2, front.second + 1));
        }
    }

    return answer;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    printf("%d", solution(N, K));
}