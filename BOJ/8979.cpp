#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct prize
{
    int country, gold, silver, bronze;

    prize(int _country, int _gold, int _silver, int _bronze) : country(_country), gold(_gold), silver(_silver), bronze(_bronze) {}
};

struct cmp
{
    bool operator()(prize a, prize b)
    {
        if (a.gold != b.gold)
        {
            return a.gold > b.gold;
        }
        else if (a.silver != b.silver)
        {
            return a.silver > b.silver;
        }
        else
        {
            return a.bronze > b.bronze;
        }
    }
} cmpObj;

bool isSame(prize a, prize b)
{
    if (a.gold == b.gold && a.silver == b.silver && a.bronze == b.bronze)
        return true;
    return false;
}

int solution(vector<prize> &input, int k)
{
    sort(input.begin(), input.end(), cmpObj);

    // for(int i = 0; i < input.size(); i++)
    //     printf("%d %d %d %d\n", input[i].country, input[i].gold, input[i].silver, input[i].bronze);

    int ans = 1;

    for (int i = 0; i < input.size(); i++)
    {
        if (i != 0 && !isSame(input[i - 1], input[i]))
            ans++;

        if (input[i].country == k)
            return ans;
    }
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    /*

    vector<prize> input;

    for(int i = 1; i <= N; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        input.push_back(prize(a,b,c,d));
    }

    printf("%d",solution(input, K));

    */

    vector<vector<int>> input(N + 1, vector<int>(3));

    for (int i = 1; i <= N; i++)
    {
        int country;
        scanf("%d", &country);

        scanf("%d %d %d", &input[country][0], &input[country][1], &input[country][2]);
    }

    int ans = 1;
    for (int i = 1; i <= N; i++)
    {
        if (i == K)
        {
            continue;
        }

        if(input[i][0] != input[K][0])
        {
            if(input[i][0] > input[K][0])
                ans++;
        }
        else if(input[i][1] != input[K][1])
        {
            if(input[i][1] > input[K][1])
                ans++;
        }
        else if(input[i][2] != input[K][2])
        {
            if(input[i][2] > input[K][2])
                ans++;
        }
    }

    printf("%d", ans);
}