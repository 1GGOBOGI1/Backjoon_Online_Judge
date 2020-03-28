#include <iostream>
using namespace std;

int main()
{
    while(1)
    {
        string input;
        cin >> input;

        if(input.compare("0") == 0)
            break;

        int i = 0;
        int j = input.size() - 1;

        while(i < j)
        {
            if(input[i] != input[j])
            {
                cout << "no\n";
                break;
            }
            i++;
            j--;
        }

        if(i >= j)
        {
            cout << "yes\n";
        }

    }
}