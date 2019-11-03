#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compare(string a, string b)
{
    if(a.length()==b.length())
        return a<b;
    else
        return a.length() <b.length();
}

int main()
{
    int N;
    cin>>N;
    vector<string> input;

    for(int i=0;i<N;i++)
    {
        string tmp;
        cin>>tmp;
        input.push_back(tmp);
    }

    sort(input.begin(), input.end(), compare);

    input.erase(unique(input.begin(), input.end()),input.end());

    for(int i=0;i<input.size();i++)
        cout<<input[i]<<endl;
}