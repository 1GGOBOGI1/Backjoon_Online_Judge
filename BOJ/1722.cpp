#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long getGroupNumber(long long k, long long fac)
{
    long long group = k / fac;
    if(k % fac == 0)
        group--;

    return group;
}

void getSequence(long long N, long long k)
{
    vector<long long> base(N);
    for(long long i = 0; i < N; i++)
        base[i] = i+1;
    
    vector<long long> factorial(N+1);
    factorial[0] = 0;
    factorial[1] = 1;
    for(long long i = 2; i < N+1; i++)
        factorial[i] = i * factorial[i-1];

    vector<long long> ans(N);

    long long cnt = 0;

    while(N-cnt >1)
    {
        cnt++;
        long long groupNum = getGroupNumber(k, factorial[N-cnt]);
        k = k - factorial[N-cnt] * groupNum;

        ans[cnt-1] = base[groupNum];
        base.erase(base.begin()+groupNum);
    }

    ans[cnt] = base[0];

    for(long long i = 0; i < ans.size(); i++)
            printf("%lld ", ans[i]);

    return ;
}

long long getRanking(long long N, vector<long long> &input)
{
    vector<long long> base(N);
    for(long long i = 0; i < N; i++)
        base[i] = i+1;
    
    vector<long long> factorial(N+1);
    factorial[0] = 0;
    factorial[1] = 1;
    for(long long i = 2; i < N+1; i++)
        factorial[i] = i * factorial[i-1];

    long long ans = 0;
    long long cnt = 0;

    while(N-cnt > 1)
    {
        long long groupNum = find(base.begin(), base.end(), input[cnt]) - base.begin();
        base.erase(base.begin()+groupNum);

        ans = ans + factorial[N-cnt-1]*groupNum;
        cnt++;
    }

    ans = ans + 1;

    return ans;
}

int main()
{
    long long N;
    scanf("%lld", &N);

    long long mode;
    scanf("%lld", &mode);

    if(mode == 1)
    {
        long long k;
        scanf("%lld", &k);

        getSequence(N, k);

    }
    else if(mode == 2)
    {
        vector<long long> input(N);
        for(long long i = 0; i < N; i++)
            scanf("%lld", &input[i]);

        printf("%lld ", getRanking(N, input));
    }
}