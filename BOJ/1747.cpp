#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void checkPrime(vector<bool> &prime)
{
    for (int i = 2; i < 2000000; i++)
    {
        if (prime[i])
        {
            for (int j = i * 2; j + i < 2000000; j = j + i)
                prime[j] = false;
        }
    }
}

bool isPalindrome(int num)
{
    string s = to_string(num);

    if(s.length() %2 == 0)
    {
        string str1 = s.substr(0,s.length()/2);
        string str2 = s.substr(s.length()/2, s.length()/2);
        reverse(str2.begin(), str2.end());
        if(str1 == str2)
            return true;
        else
            return false;
    }
    else
    {
        string str1 = s.substr(0,s.length()/2);
        string str2 = s.substr(s.length()/2 + 1, s.length()/2);
        reverse(str2.begin(), str2.end());
        if(str1 == str2)
            return true;
        else
            return false;
    }
    
}

int main()
{
    vector<bool> prime(2000000, true);
    checkPrime(prime);
    prime[1] = false;

    int N;
    scanf("%d", &N);

    for(int i = N; i < 2000000; i++)
        if(prime[i] && isPalindrome(i))
        {
            printf("%d", i);
            return 0;
        }
}