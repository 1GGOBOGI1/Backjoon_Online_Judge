#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long min, max;
    cin >> min >> max;
    
    vector<bool> check(max-min+1,true);

    long long ans = 0;

    for(long long i = 2; i*i < max+1; i++)
    {
        //printf("i = %lld\n",i);

        long long n = i*i;
        long long offset = 0;

        if(min%n == 0)
            offset = min;
        else 
            offset = min - (min%n) + n;
            
        for(int m = 0; offset + n*m <= max; m++)
        {
            //printf("n = %lld\n",n);
            check[offset + n*m - min] = false;
        }
    }

    for(long long i = 0; i < max-min+1;i++)
        if(check[i])
            ans++;

    cout << ans;
}