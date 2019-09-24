#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;

    int A[N];

    for (int i = 0; i < N;i++)
        cin >> A[i];

    int ans = 0, left = 0, right = 0,sum = A[left];

    while(right<N&&left<N)
    {
        if (sum == M)
        {
            ans++;
            right++;
            sum += A[right];
        }

        if(sum>M)
        {
            sum -= A[left];
            left++;
            if (left > right)
            {
                left = right;
                sum = A[left];
            }
        }
        else if (sum<M)
        {
            right++;
            sum += A[right];
        }
    }

    cout << ans;

    return 0;
}