#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int cards[n];
    for (int i = 0; i < n;i++)
        cin >> cards[i];

    int max = 0, sum = 0;
    for (int i = 0; i <= n - 3; i++)
    {
        sum = cards[i] + cards[i + 1] + cards[i + 2];

        if(sum>m)
            continue;
        
        if(m-max>m-sum)
            max = sum;
    }
    cout << max;
}