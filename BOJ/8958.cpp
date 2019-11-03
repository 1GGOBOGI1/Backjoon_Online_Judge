#include <iostream>
using namespace std;

int main()
{
    int T,score = 0,cont=0;
    cin >> T;

    string input;

    while (T--)
    {
        score = 0;

        cin >> input;

        for (int i = 0; i < input.length();i++)
        {
            if (input[i] == 'O')
            {
                cont++;
            }
            else
            {
                score += cont;
                cont = 0;
            }
        }

        score += cont;
        cont = 0;

        cout << score << endl;
    }
}