#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    string input;
    cin >> input;

    int num[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    stack<double> s;

    for (int i = 0; i < input.size(); i++)
    {
        if ('A' <= input[i] && input[i] <= 'Z') //연산자가 아니면 스택에 처넣음
        {
            s.push(num[input[i] - 'A']);
            continue;
        }

        if (s.size() >= 2)
        {
            // 연산자이면 스택 두개 꺼내서 연산하고 결과 처넣음
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();

            double result;

            switch (input[i])
            {
            case '+':
                result = b + a;
                break;
            case '-':
                result = b - a;
                break;
            case '*':
                result = b * a;
                break;
            case '/':
                result = b / a;
                break;
            }
            s.push(result);
        }
        else
        {
            printf("error!\n");
        }   
    }

    printf("%.2f", s.top());
}