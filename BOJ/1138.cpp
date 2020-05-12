/*
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int P[N], ANS[N] = {0};
    for (int i = 0; i < N; i++)
        cin >> P[i];
    for (int i = 0; i < N; i++)
    {
        int cnt = 0, j = 0;
        for (; cnt != P[i] + 1; j++)
            if (ANS[j] == 0)
                cnt++;
        ANS[j - 1] = i + 1;
    }
    for (int i = 0; i < N; i++)
        cout << ANS[i] << " ";
}
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int people[N + 1] = {0};
    int answer[N + 1] = {0};

    for (int i = 1; i <= N; i ++)
        scanf("%d", &people[i]);

    for (int i = 1; i <= N; i++)
    {
        int cnt = 0, j = 1;

        for (; cnt != people[i]+1; j++)
        {
            if(answer[j] == 0)
                cnt++;
        }
        answer[j-1] = i;
    }

    for (int i = 1; i <= N; i++)
        printf("%d ", answer[i]);
}