#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        bool princesses[n + 1] = {false};
        bool princes[n + 1] = {false};
        int remainPrincesses = 0;
        for (int j = 1; j <= n; j++)
        {
            int k;
            cin >> k;
            for (int z = 0; z < k; z++)
            {
                int p;
                cin >> p;
                if (!princesses[j] && !princes[p])
                {
                    princesses[j] = true;
                    princes[p] = true;
                }
            }

            if (!princesses[j])
                remainPrincesses = j;
        }

        if (remainPrincesses == 0)
        {
            cout << "OPTIMAL\n";
        }
        else
        {
            int remainPrince = 0;
            for (int j = 1; j <= n; j++)
            {
                if (!princes[j])
                {
                    remainPrince = j;
                    break;
                }
            }

            cout << "IMPROVE\n"
                 << remainPrincesses << " " << remainPrince << "\n";
        }
    }
}