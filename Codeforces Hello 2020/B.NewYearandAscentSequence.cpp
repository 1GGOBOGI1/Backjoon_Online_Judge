#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,l,input;
    cin >> n;

    vector<vector<int> > sequences;

    for (int i = 0; i < n;i++)
    {
        cin >> l;
        vector<int> tmp;
        for (int j = 0; j < l; j++)
        {
            cin >> input;
            tmp.push_back(input);
        }
        sequences.push_back(tmp);
    }
    
}