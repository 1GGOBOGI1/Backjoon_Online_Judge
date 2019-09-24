#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void subset(vector<vector<int>> people, vector<vector<int>> A, int index)
{
    if(A.size()==3||index=num)

}

int main()
{
    int n;
    cout << "input n: ";
    cin >> n;

    vector<vector<int>> people(n, vector<int>(n, 0));
    vector<int> people_index(n);
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        int friend_num;
        cin >> friend_num;
        people_index[i] = i;
        for (int j = 0; j < friend_num; j++)
        {
            int tmp;
            cin >> tmp;
            people[i].push_back(tmp);
        }
    }
}