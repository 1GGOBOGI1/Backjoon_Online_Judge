#include<iostream>
using namespace std;

int main()
{
    int input[8];
    for (int i = 0; i < 8;i++)
        cin >> input[i];

    string ans = "";

    if(input[0]<input[1])
        ans = "ascending";
    else if(input[0]>input[1])
        ans = "descending";

    for (int i = 1; i < 7;i++)
    {
        if (ans == "ascending" && input[i] > input[i+1])
        {
            ans = "mixed";
            break;
        }
        else if (ans == "descending" && input[i] < input[i + 1])
        {
            ans = "mixed";
            break;
        }
    }

    cout << ans;
}