#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    if((a[0]+a[1]+a[2]+a[3])%2)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        sort(a, a + 4);

        if((a[0]+a[1]+a[2])==a[3]||(a[0]+a[1])==(a[2]+a[3])||(a[0]+a[2])==(a[1]+a[3])||(a[0]+a[3])==(a[1]+a[2]))
        {
            cout << "YES";
            return 0;
        }
        else
        {
            cout << "NO";
            return 0;
        }
        
    }
    
}