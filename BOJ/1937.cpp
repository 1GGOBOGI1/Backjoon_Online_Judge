#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> input;
vector<vector<int>> ans;
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, 1, -1, 0};
int n;
int maxDay = 0;

int eat(int i,int j)
{
    if(ans[i][j] != 0)
        return ans[i][j];

    ans[i][j] = 1;

    for (int x = 0; x < 4; x++)
    {
        int ni = i + di[x];
        int nj = j + dj[x];

        if(ni < 0 || nj < 0 || ni >=n || nj >=n)
            continue;
        
        if(input[i][j] >= input[ni][nj])
            continue;

        ans[i][j] = max(ans[i][j], eat(ni, nj)+1);
    }
    return ans[i][j];
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        vector<int> tmp(n, 0);
        vector<int> tmp2(n, 0);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &tmp[j]);
        }
        input.push_back(tmp);
        ans.push_back(tmp2);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            maxDay = max(maxDay,eat(i, j));

    printf("%d", maxDay);
}