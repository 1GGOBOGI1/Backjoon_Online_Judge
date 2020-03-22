#include <iostream>
using namespace std;

string solution(string &S)
{
    int length = S.length();
    int front = 0;
    int end = length-1;

    while(front < end)
        {
            if(S[front]=='?' && S[end]=='?')
            {
                S[front] = 'a';
                S[end] = 'a';
            }
            else if(S[frnot]=='?' || S[end]== '?')
            {
                if(S[front] == '?')
                {
                    S[front] = S[end];
                }
                else
                {
                    S[end] = S[front];
                }
            }
            else
            {
                if(S[front] != S[end])
                    return "NO";
            }
            front++;
            end--;
        }
        return S;
}

int main()
{
    string S;
    cin>>S;

    cout<< solution(S);
}