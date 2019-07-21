#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string input_string = "";
    string all = "";

    while (all != ".")
    {
        stack<char> matching;
        bool check = true;
        all = "";
        input_string = "";

        while (input_string.back() != '.')
        {
            getline(cin, input_string);
            all += input_string;
        }

        for (int i = 0; i < all.size() && check == true; i += 1)
        {
            if (all[i] == '(' || all[i] == '[')
            {
                matching.push(all[i]);
            }
            else if (all[i] == ')')
            {
                if (!matching.empty() && matching.top() == '(')
                    matching.pop();
                else
                    check = false;
            }
            else if (all[i] == ']')
            {
                if (!matching.empty() && matching.top() == '[')
                    matching.pop();
                else
                    check = false;
            }
        }

        if (all == ".")
            exit(0);
            
        if (check && matching.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}