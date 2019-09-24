#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    char input[N][M];
    string now_input;

    for (int i = 0; i < N; i++)
    {
        cin >> now_input;
        for (int j = 0; j < M; j++)
            input[i][j] = now_input[j];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // cout << "M - 1 + i = " << M - 1 - i << " N - 1 + j = " << N - 1 - j << endl;
            switch (input[j][M - 1 - i])
            {
            case 46:
                cout << ".";
                break;
            case 79:
                cout << "O";
                break;
            case 45:
                cout << "|";
                break;
            case 124:
                cout << "-";
                break;
            case 47:
                cout << "\\";
                break;
            case 92:
                cout << "/";
                break;
            case 94:
                cout << "<";
                break;
            case 60:
                cout << "v";
                break;
            case 118:
                cout << ">";
                break;
            case 62:
                cout << "^";
                break;
            }
        }
        cout << "\n";
    }
}