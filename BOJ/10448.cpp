#include <iostream>
using namespace std;
int num[47];
bool combi[1001];
int main()
{
    int n, t;
    cin >> t;
    for (int i = 1; i < 46; i++)
    {
        num[i] = i * (i + 1) / 2;
    }
    for (int i = 1; i < 46; i++)
    {
        for (int j = 1; j < 46; j++)
        {
            for (int k = 1; k < 46; k++)
            {
                int tmp = num[i] + num[j] + num[k];
                if (tmp < 1001)
                {
                    combi[tmp] = true;
                }
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        if (combi[n] == true)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}