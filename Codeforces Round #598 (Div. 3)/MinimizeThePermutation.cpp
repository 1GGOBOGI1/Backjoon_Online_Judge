#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 9999;
using namespace std;

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size();i++)
        cout << v[i] << " ";
    cout << "\n";
}

void make_vector(vector<int> input, vector<int> sub_value, vector<bool> check, bool flag)
{
    if(flag)
    {
        return print_vector(input);
    }

    int index = min_element(sub_value.begin(), sub_value.end()) - sub_value.end();
    if(!check[index])
    {
        sub_value[index] = MAX;
    }
}

int main()
{
    int q;
    cin >> q;

    int n,tmp;
    bool flag = false;
    vector<int> input;
    vector<int> sub_value;

    while (q--)
    {
        input.clear();
        sub_value.clear();

        cin >> n;
        cin >> tmp;
        input.push_back(tmp);
        vector<bool> check(n,true);
        for (int i = 1; i < n; i++)
        {
            cin >> tmp;
            input.push_back(tmp);
            sub_value.push_back(input[i] - input[i - 1]);
            if(flag != true && sub_value[i-1] < 0)
                flag = true;
        }

    }
}