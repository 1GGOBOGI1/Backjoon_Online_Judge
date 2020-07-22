#include <iostream>
#include <algorithm>
using namespace std;

string solution(int N, int B)
{
    string ans = "";

    while(N > 0)
    {
        int r = N % B;
        N = N / B;


        if(r < 10)
            ans += to_string(r);
        else
        {
            ans += char('A' + r-10);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int N, B;
    scanf("%d %d", &N, &B);

    printf("%s", solution(N, B).c_str());

}