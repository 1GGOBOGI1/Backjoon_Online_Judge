#include <iostream>
#include <string>
#include <queue>
using namespace std;

vector<vector<int>> ans;

struct thing
{
    int index, value, weight;
};

void subset(vector<thing> things, vector<thing> ans_things, vector<thing>::iterator things_start)
{
    if (ans_things.size() == 4)
    {
        for(int i=0)
    }
}

void find_ans(thing _things[], int start, int end)
{
}
int main()
{
    int num, bag_weight;
    cin >> num >> bag_weight;
    vector<thing> things(num);

    for (int i = 0; i < num; i++)
    {
        thing tmp;
        tmp.index = i;
        cin >> tmp.value;
        things.push_back(tmp);
    }

    for (int i = 0; i < num; i++)
        cin >> things[i].weight;
}