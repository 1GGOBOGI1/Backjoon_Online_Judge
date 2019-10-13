#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void* a,const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1<num2)
        return -1;
    if(num1>num2)
        return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int num[n];

    for (int i = 0;i<n;i++)
        cin >> num[i];
    
    qsort(num, n, sizeof(int), compare);

    for (int i = 0; i < n;i++)
        cout << num[i] << '\n';
}
