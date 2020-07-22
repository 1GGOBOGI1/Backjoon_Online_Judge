#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

struct position
{
    int start, end;
    position(int _start, int _end) : start(_start), end(_end) {}
};

void getPositions(string input, vector<position> &p, bitset<200> &base)
{
    stack<int> q;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
            q.push(i);
        else if (input[i] == ')')
        {
            p.push_back(position(q.top(), i));
            q.pop();
        }
        else
        {
            base[i] = 1;
        }
    }
}

string getString(int bitmask, string input, vector<position> p, bitset<200> base)
{
    int cnt = 0;

    while (bitmask >= (1 << cnt))
    {
        if (bitmask & (1 << cnt))
        {
            base[p[cnt].start] = 1;
            base[p[cnt].end] = 1;
        }
        cnt++;
    }

    string str = "";

    for (int i = 0; i < input.size(); i++)
        if (base.test(i))
            str += input[i];

    return str;
}

int main()
{
    // for testing dataset
    /*
    string BASE_PATH = "/home/juhui/Downloads/contest6_testdata/zagrade/";

    for (int i = 1; i <= 10; i++)
    {
        string FILE_NAME = "zagrade.in." + to_string(i);

        ifstream ifs(BASE_PATH + FILE_NAME);

        printf("[start] %s\n",FILE_NAME.c_str());

        string input;
        //cin >> input;
        getline(ifs, input);

        bitset<200> base;

        vector<position> p;

        getPositions(input, p, base);

        int max = (1 << p.size()) - 1;

        vector<string> answers;

        for (int bitmask = 0; bitmask < max; bitmask++)
        {
            answers.push_back(getString(bitmask, input, p, base));
        }

        sort(answers.begin(), answers.end());
        answers.erase(unique(answers.begin(), answers.end()), answers.end());

        string RESULT_NAME = "zagrade.out." + to_string(i);
        ifstream result(BASE_PATH + RESULT_NAME);

        string rst;

        for (int i = 0; i < answers.size(); i++)
        {
            getline(result, rst);
            if(answers[i] != rst)
            {
                printf("catch wrong answer!!\nyour answer:\t %s\nanswer:\t\t %s\n",answers[i].c_str(),rst.c_str());
                return 0;
            }
            //printf("%s\n", answers[i].c_str());

        }

        ifs.close();
    }
    */

    string input;
    cin >> input;

    bitset<200> base;

    vector<position> p;

    getPositions(input, p, base);

    int max = (1 << p.size()) - 1;

    vector<string> answers;

    for (int bitmask = 0; bitmask < max; bitmask++)
    {
        answers.push_back(getString(bitmask, input, p, base));
    }

    sort(answers.begin(), answers.end());
    answers.erase(unique(answers.begin(), answers.end()), answers.end());

    for (int i = 0; i < answers.size(); i++)
    {
        printf("%s\n", answers[i].c_str());
    }
}