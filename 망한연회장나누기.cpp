#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;

int min_cut;
int num;

void make_partition(vector<vector<int>> people, vector<int> people_index, vector<int> A)
{
    vector<int> B = people_index;
    int cut = 0;
    for (int i = 0; i < A.size(); i++)
    {
        auto iter = find(B.begin(), B.end(), A[i]);
        if (iter != B.end())
            cut++;
    }

    if (cut < min_cut)
    {
        min_cut = cut;
        vector<int> _ans(A.size() + B.size());
        _ans.insert(_ans.end(), A.begin(), A.end());
        _ans.insert(_ans.end(), B.begin(), B.end());
    }
}

void subset(vector<vector<int>> people,vector<int> people_index, vector<int> A, int n)
{
    if (A.size() == n || people_index.size() == 0)
    {
        if (A.size() == n)
            make_partition(people_index, A);
        return;
    }

    subset(people_index, A, n);
    A.push_back(people_index[0]);
    people_index.erase(people_index.begin());
    subset(people_index, A, n);
}

int main()
{
    cout << "inut n:";
    cin >> num;

    vector<vector<int>> people(num,vector<int>(num,0));
    vector<int> people_index(num);
    for (int i = 0; i < num; i++)
    {
        cout << i << ": ";
        int _num;
        cin >> _num;
        cout << "_num = " << _num << endl;
        people_index.push_back(i);
        for (int j = 0; j < _num; j++)
        {
            int tmp;
            cin >> tmp;
            people[i].push_back(tmp);
        }
    }

    cout << "cut: " << min_cut;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}