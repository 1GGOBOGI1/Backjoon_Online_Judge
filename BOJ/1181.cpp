/*
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

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
    if(a.size() < b.size())
        return true;
    else if(a.size() == b.size())
        return a < b;
    return false;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    vector<string> str(N);
    
    for(int i = 0; i < N; i++)
        cin >> str[i];
        
        
    
    sort(str.begin(), str.end(), compare);
    str.erase(unique(str.begin(), str.end()),str.end());
    
    
    for(int i = 0; i < str.size(); i++)
        cout<<str[i]<<"\n";    
    
}
