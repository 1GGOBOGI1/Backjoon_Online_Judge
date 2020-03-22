#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    int length = A.size() + 1;
    int ans[2] = {0};

    for(int i=1;i<length;i++)
    {
        if(i%2) // i가 홀수이면
        {
            ans[0] += A[i-1] ^ 1;
            ans[1] += A[i-1] ^ 0;
        }
        else
        {
            ans[0] += A[i-1] ^ 0;
            ans[1] += A[i-1] ^ 1;
        }
    }

    if(ans[0] < ans[1])
        return ans[0];
    else
        return ans[1];
}

int main()
{

}