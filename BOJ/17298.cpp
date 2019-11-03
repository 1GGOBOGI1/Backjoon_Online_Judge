#include<iostream>
#include<stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> input;
    stack<int> ans;
    int N, tmp;
    cin >> N;

    for (int i = 0; i < N;i++)
    {
        cin >> tmp;
        input.push(tmp);
    }

    ans.push(-1);
    int max = input.top(), cnt = 0;
    input.pop();

    while(!input.empty())
    {
        if(input.top() > max)
        {
            for (int i = 0; i < cnt;i++)
            {
                ans.push(max);
                max = input.top();
            }
        }
        else
        {
            cnt++;
            input.pop();
        }
        }
}