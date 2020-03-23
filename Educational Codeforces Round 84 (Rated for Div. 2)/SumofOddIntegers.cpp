#include <iostream>
using namespace std;

string answer(int n, int k, int m)
{
    int lastOdd;
    if(m == 0)
        lastOdd = 0;
    else
        lastOdd = 2 * (m - 1) + 1;
    
    int odd = 2 * m + 1;

    if(n < odd)
        return "NO";

    if (k == 1)
    {
        if (n % 2)
        {
            if (n < lastOdd)
                return "NO";
            else
                return "YES";
        }
        else
            return "NO";
    }
    else
    {
        if (k % 2) // k가 홀수 -> n은 무조건 홀수여야 함
        {
            if (n % 2) // n이 홀수
                return answer(n - odd, k - 1, m + 1);
            else // n이 짝수
                return "NO";
        }
        else // k가 짝수 -> n은 무조건 짝수여야 함
        {
            if (n % 2) // n이 홀수
                return "NO";
            else // n이 짝수
                return answer(n - odd, k - 1, m + 1);
        }
    }
}

int main()
{

    int n, k, t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        cout << answer(n, k, 0)<<"\n";
    }
}