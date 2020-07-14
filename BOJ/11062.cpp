#include <iostream>
#include <vector>
using namespace std;

bool canTake(int left, int right, bool flag, vector<int> c)
{
    if (flag == true)
    {
        if (left + 1 <= right)
        {
            if (c[left + 1] <= c[right])
                return true;
            else
                return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if (left <= right - 1)
        {
            if (c[left] >= c[right - 1])
                return true;
            else
                return false;
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N;
        scanf("%d", &N);

        vector<int> c(N);

        for (int i = 0; i < N; i++)
            scanf("%d", &c[i]);

        int left = 0, right = N - 1;

        long long score = 0;
        bool flag = true;

        while (left <= right)
        {
            // printf("left = %d, right = %d\n", left, right);
            // printf("flag = %d\n", flag ? 1 : 0);
            if (c[left] > c[right])
            {
                // printf("can take left?\n");
                if (canTake(left, right, true, c))
                {
                    // printf("yes\n");
                    if (flag == true)
                    {
                        // printf("take %d\n", c[left]);
                        score += c[left];
                    }

                    left++;
                }
                else
                {
                    // printf("no\n");
                    if (flag == true)
                    {
                        // printf("take %d\n", c[right]);
                        score += c[right];
                    }
                    right--;
                }
            }
            else
            {
                //printf("can take right?\n");
                if (canTake(left, right, false, c))
                {
                    if (flag == true)
                    {
                        //printf("yes\n");
                        //printf("take %d\n", c[right]);
                        score += c[right];
                    }
                    right--;
                }
                else
                {
                    if (flag == true)
                    {
                        //printf("no\n");
                        //printf("take %d\n", c[left]);
                        score += c[left];
                    }

                    left++;
                }
            }

            flag = !flag;
        }

        printf("%lld\n", score);
    }
}