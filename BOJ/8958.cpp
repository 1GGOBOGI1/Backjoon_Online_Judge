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
                for (int j = 1; j <= cont;j++)
                    score += j;
                cont = 0;
            }
        }

        for (int j = 1; j <= cont; j++)
            score += j;
        cont = 0;

        cout << score << endl;
    }
}