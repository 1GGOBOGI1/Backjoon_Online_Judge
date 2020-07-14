#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

long long solution(vector<int> &input)
{
    long long answer = 0;
    for (int i = 0; i < input.size() - 1; i++)
        for (int j = i + 1; j < input.size(); j++)
            answer += GCD(input[i], input[j]);
    return answer;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        vector<int> input(n);

        for (int i = 0; i < n; i++)
            scanf("%d", &input[i]);

        printf("%lld\n", solution(input));
    }
}