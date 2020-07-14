#include <iostream>
#include <vector>
using namespace std;

struct price
{
    int min,max;
    price(int _min, int _max):min(_min), max(_max){}
};

int main()
{
    int n;
    long long W;
    scanf("%d %lld", &n, &W);
    vector<int> m(n);

    for(int i = 0; i < n; i++)
        scanf("%d", &m[i]);

    bool flag = false;

    long long coins = 0;

    for(int i = 0; i < n-1; i++)
    {
        if(m[i] < m[i+1] && flag == false)
        {
            //printf("buy %d\n", m[i]);
            coins += W / m[i];
            W = W % m[i];
            flag = true;
        }
        else if(m[i] > m[i+1] && flag == true)
        {
            //printf("sell %d\n", m[i]);
            W = W + coins * m[i];
            coins = 0;
            flag= false;
        }
    }

    if(coins != 0)
        W = W + coins * m[n-1];

    printf("%lld", W);
}