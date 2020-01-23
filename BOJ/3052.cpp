#include<iostream>
#include<set>
using namespace std;

int main()
{
    int input, num;

    set<int> data;

    for (int i = 0; i < 10;i++)
    {
        cin >> input;
        num = input % 42;
        data.insert(num);
    }

    cout << data.size() << endl;
}