#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compair(pair<int,int> a, pair<int,int> b)
{
    if(a.first==b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int> > input;

    for (int i = 0; i < N;i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        input.push_back(tmp);
    }

    sort(input.begin(),input.end(),compair);

    for(int i=0;i<N;i++)
         cout << input[i].first<<" "<<input[i].second<<"\n"; 

}