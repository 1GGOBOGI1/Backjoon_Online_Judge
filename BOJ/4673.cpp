/*

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

*/

#include <iostream>
#include <cstring>
using namespace std;

void checkSelfNumber(bool * isSelfNumber, int index)
{
    if(index > 10001)
        return;

    int num = index;

    while(index != 0)
    {
        num += index % 10;

        index /= 10;
    }

    if(num > 10001)
        return;

    if(!isSelfNumber[num])
        return;

    isSelfNumber[num] = false;
    checkSelfNumber(isSelfNumber, num);
}

int main()
{
    bool isSelfNumber[10001];

    memset(isSelfNumber,true, sizeof(isSelfNumber));

    for (int i = 1; i < 10001; i++)
        if(isSelfNumber[i])
            checkSelfNumber(isSelfNumber, i);

    for (int i = 1; i < 10001; i++)
        if(isSelfNumber[i])
            printf("%d\n", i);
}