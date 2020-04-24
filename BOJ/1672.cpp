#include <iostream>
using namespace std;

string DNAChart[4] = {"ACAG", "CGTA", "ATCG", "GAGT"};

int stringToNum(char a)
{
    if(a == 'A')
        return 0;
    else if(a == 'G')
        return 1;
    else if(a == 'C')
        return 2;
    else if(a == 'T')
        return 3;

    return -1;
}

char changeDNA(char _a, char _b)
{
    int a = stringToNum(_a);
    int b = stringToNum(_b);

    return DNAChart[a][b];
}

int main()
{
    int N;
    cin >> N;

    string dna;
    cin >> dna;

    for (int i = N - 1; i > 0; i--)
    {
        dna[i-1] = changeDNA(dna[i], dna[i - 1]);
    }

    cout << dna[0];
}