#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    long long num = A * B * C;

    int cnt[10];
    memset(cnt, 0, sizeof(cnt));

    while(num != 0)
    {
        int index = num % 10;
        cnt[index]++;
        num = num / 10;
    }

    for (int i = 0; i < 10;i++)
    {
        cout << cnt[i] << endl;
    }
}