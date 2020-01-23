#include <iostream>
#include <cstring>
using namespace std;

void check(bool* selfnumber,int i)
{
    //cout << "i = " << i << "\n";
    if (i > 10001)
        return;

    int num = i;
    while(i!=0)
    {
        num += i % 10;
        i = i / 10;
    }
    if(num>10001)
        return;
    if(selfnumber[num]==false)
        return;
    //cout << "num = " << num << "\n";
    selfnumber[num] = false;
    check(selfnumber,num);
}

int main()
{
    bool selfnumber[10001];
    memset(selfnumber, true, sizeof(selfnumber));
    // selfnumber[i] = true 이면 생성자가 없는 것
    for (int i = 1; i < 10001; i++)
        if(selfnumber[i])
            check(selfnumber, i);

    int ans = 0;
    for (int i = 1; i < 10001; i++)
        if (selfnumber[i])
            cout << i << "\n";
}