#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin >> num[i];

    cout << *min_element(num, num + n) << " " << *max_element(num, num + n);
}