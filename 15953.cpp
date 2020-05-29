#include <iostream>
#include <vector>
using namespace std;

struct code2017
{
    int limit_ranking = 6;
    int rewards[7] = {0, 500, 300, 200, 50, 30, 10};
    int limit[7] = {0, 1, 2, 3, 4, 5, 6};
    vector<int> ranking;

    code2017()
    {
        ranking.assign(limit_ranking + 1, 0);
        for (int i = 1; i < limit_ranking + 1; i++)
        {
            ranking[i] = ranking[i - 1] + limit[i];
        }
    }

    int getReward(int a)
    {
        int reward = 0;

        if (ranking[limit_ranking] < a)
            return reward;

        for (int i = limit_ranking; i > 0; i--)
        {
            if (ranking[i - 1] < a && a <= ranking[i])
            {
                reward = rewards[i]* 10000;
                break;
            }
        }

        return reward;
    }
};

struct code2018
{
    int limit_ranking = 5;
    int rewards[6] = {0, 512, 256, 128, 64, 32};
    int limit[6] = {0, 1, 2, 4, 8, 16};
    vector<int> ranking;

    code2018()
    {
        ranking.assign(limit_ranking + 1, 0);
        for (int i = 1; i < limit_ranking + 1; i++)
        {
            ranking[i] = ranking[i - 1] + limit[i];
        }
    }

    int getReward(int a)
    {
        int reward = 0;

        if (ranking[limit_ranking] < a)
            return reward;

        for (int i = limit_ranking; i > 0; i--)
        {
            if (ranking[i - 1] < a && a <= ranking[i])
            {
                reward = rewards[i] * 10000;
                break;
            }
        }
        return reward;
    }
};

int main()
{
    int T;
    scanf("%d", &T);

    code2017 c_2017;
    code2018 c_2018;

    while (T--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", c_2017.getReward(a) + c_2018.getReward(b));
    }
}