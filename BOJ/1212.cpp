#include <iostream>
#include <cmath>
using namespace std;

string solution(string input)
{
    string answer = "";

    for (int i = 0; i < input.size(); i++)
    {
        int num = (input[i] - '0');

        if(num/4 == 1)
            answer += "1";
        else if(answer != "")
            answer += "0";

        num = num % 4;

        if(num/2 == 1)
            answer += "1";
        else if(answer != "")
            answer += "0";
        num = num % 2;

        if(num != 0)
            answer += "1";
        else if(answer != "")
            answer += "0";
    }

    if(answer == "")
        answer = "0";

    return answer;
}

int main()
{
    string input;
    cin >> input;

    printf("%s", solution(input).c_str());
}