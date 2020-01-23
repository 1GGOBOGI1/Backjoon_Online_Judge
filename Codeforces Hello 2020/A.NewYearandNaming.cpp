#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> N;
    vector<string> M;

    string input;

    for (int i = 0; i < n;i++){
        cin >> input;
        N.push_back(input);
    }

    for (int i = 0; i < m;i++)
    {
        cin >> input;
        M.push_back(input);
    }

    int q,year,idx1, idx2;
    cin >> q;

    while(q--)
    {
        cin >> year;

        if(year == 1)
        {
            cout << N[0] << M[0] << "\n";
            continue;
        }

        cout<< N[(year - 1)%n] << M[(year - 1)%m] << "\n";
    }
}