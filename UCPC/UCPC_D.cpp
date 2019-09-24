#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    map<string, int> dictionary[26];

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        int dic_pos = input[0] - 'a';

        auto iter = dictionary[dic_pos].find(input);

        if (iter != dictionary[dic_pos].end()) //지금 들어온 단어가 사전에 없을때
        {
            dictionary[dic_pos].insert(make_pair(input, 1));
        }
        else //지금 들어온 단어가 사전에 있을때
        {
            dictionary[dic_pos][input]++;
        }
    }

    string word;
    cin >> word;

    
}