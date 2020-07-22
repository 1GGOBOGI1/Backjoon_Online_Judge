#include <iostream>
#include <cmath>
using namespace std;

int solution(string N, int B)
{
    int ans = 0;

    for (int i = 0; i < N.size(); i++)
    {
        if('0'<= N[i] && N[i] <= '9')
            ans += (N[i] - '0') *pow(B, N.size() - 1 - i);
        else
            ans += (N[i] - 'A' + 10) *pow(B, N.size() - 1 - i);
    }

    return ans;
}

int main()
{
    string N;
    int B;
    cin >> N >> B;

    printf("%d", solution(N, B));
}