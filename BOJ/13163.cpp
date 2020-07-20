#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    string prefix = "god";

    cin.ignore();

    for (int i = 0; i < N; i++)
    {

        string input;

        getline(cin, input);

        bool flag = false;

        string name = "god";

        for(int i = 0; i < input.length(); i++)
        {
            if(!flag && input[i] == ' ')
            {
                flag = !flag;
            }
            else if(flag)
            {
                if(input[i] != ' ')
                    name += input[i];
            }
        }

        printf("%s\n", name.c_str());
    }
}