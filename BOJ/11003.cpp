#include<iostream>
#include<deque>
using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;

    int input[N + 1];
    for (int i = 1; i < N + 1;i++)
        cin >> input[i];

    deque<pair<int, int>> q;

    q.push_back(make_pair(input[1], 1));

    for (int i = 1; i < N + 1;i++)
    {
        pair<int, int> front_value = q.front();
        while(!(front_value.second<i-L+1))
        {
            q.pop_front();
            front_value = q.front();
        }

        
    }
}