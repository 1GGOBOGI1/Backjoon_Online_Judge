#include <iostream>
#include <vector>
using namespace std;

void whoWin(vector<bool> &row, vector<bool> &col)
{
    string winner = "Vivek";
    bool flag = true;

    while (flag)
    {
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i])
            {
                for (int j = 0; j < col.size(); j++)
                {
                    if (col[j])
                    {
                        row[i] = false;
                        col[j] = false;
                        winner == "Ashish" ? winner = "Vivek" : winner = "Ashish";
                        break;
                    }
                    else
                    {
                        flag = false;
                    }
                }
                break;
            }
            else
            {
                flag = false;
            }
        }
    }

    printf("%s\n", winner.c_str());
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        vector<bool> row(n, true);
        vector<bool> col(m, true);

        int input;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &input);

                if (input == 1)
                {
                    row[i] = false;
                    col[j] = false;
                }
            }
        }
        whoWin(row, col);
    }
}