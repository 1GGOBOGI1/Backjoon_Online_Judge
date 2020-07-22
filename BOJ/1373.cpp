#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string solution(string input)
{
    string answer = "";

    reverse(input.begin(), input.end());
    int i = 2;

    for (i = 2; i < input.size(); i = i +3)
    {
        answer += to_string((input[i] - '0') * 4 + (input[i - 1]-'0') * 2 + (input[i - 2]-'0') * 1);
    }
    i = i - 2;

    if(input.size()-1-i == 1)
    {
        answer += to_string((input[i]-'0') * 1 + (input[i + 1]-'0') * 2);
    }
    else if(input.size()-1-i == 0)
    {
        answer += to_string((input[i]-'0') * 1);
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    string input;
    cin >> input;

    printf("%s", solution(input).c_str());
}