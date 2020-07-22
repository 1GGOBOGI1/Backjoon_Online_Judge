#include <iostream>
using namespace std;

string solution(int A, int B)
{
    string answer = "";

    int numSize;
    scanf("%d", &numSize);

    int originNum = 0;

    for (int i = 0; i < numSize; i++)
    {
        int input;
        scanf("%d", &input);

        originNum = originNum * A + input;
    }

    while(originNum != 0)
    {
        int remainder = originNum % B;

        answer = " " + answer;
        answer = to_string(remainder) + answer;

        originNum /= B;
    }

    if(answer == "")
        answer = "0";

    return answer;
}

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    printf("%s", solution(A, B).c_str());
}