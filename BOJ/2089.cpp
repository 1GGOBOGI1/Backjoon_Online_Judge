/*
#include <iostream>
using namespace std;

string solution(int N)
{
    string answer = "";

    while (N != 0)
    {
        switch (N % -2)
        {
        case -1:
            answer = "1" + answer;
            N = (N - 1) / -2;
            break;
        case 1:
            answer = "1" + answer;
            N = (N-1) / -2;
            break;
        case 0:
            answer = "0" + answer;
            N = N / -2;
            break;
        }
    }

    if(answer == "")
        answer = "0";

    return answer;
}
int main()
{
    int N;
    scanf("%d", &N);

    printf("%s", solution(N).c_str());
}
*/

#include <iostream>
using namespace std;

string solution(int input)
{
    string answer = "";

    while(input != 0)
    {
        switch(input % -2)
        {
            case 0:
                answer = "0" + answer;
                input /= -2;
                break;
            case 1:
                answer = "1" + answer;
                input = (input - 1) / -2;
                break;
            case -1:
                answer = "1" + answer;
                input = (input - 1) / -2;
                break;
        }
    }

    if(answer == "")
        answer = "0";

    return answer;
}

int main()
{
    int input;
    scanf("%d", &input);

    printf("%s", solution(input).c_str());
}