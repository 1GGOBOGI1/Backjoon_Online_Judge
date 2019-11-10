#include <iostream>
#include <cstring>
using namespace std;

void check(bool* selfnumber,int i)
{
    cout << "i = " << i << "\n";
    if (i > 10000)
        return;

    int num = i;
    while(i!=0)
    {
        num += i % 10;
        i = i / 10;
    }
    if(num>10000)
        return;
    if(selfnumber[num]==false)
        return;
    cout << "num = " << num << "\n";
    selfnumber[num] = false;
    check(selfnumber,num);
    return;
}

int main()
{
    bool *selfnumber;
    selfnumber = new bool[100001];
    memset(selfnumber, true, sizeof(*selfnumber));

    check(selfnumber, 1);

    for (int i = 1; i < 10001; i++)
        if(selfnumber[i])
            cout << i << "\n";
}