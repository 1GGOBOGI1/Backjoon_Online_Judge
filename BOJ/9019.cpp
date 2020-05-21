#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct reg
{
    int n;
    string command = "";

    reg(int _n, string _command) : n(_n), command(_command) {}
    reg(int _n) : n(_n) {}
    reg() {}
};

int D(int n)
{
    int result = 0;

    result = n * 2;

    if (result > 9999)
        result = result % 10000;

    return result;
}

int S(int n)
{
    int result = 0;

    n == 0 ? result = 9999 : result = n - 1;

    return result;
}

int L(int n)
{
    int result = 0;

    result = (n % 1000) * 10 + (n / 1000);

    return result;
}

int R(int n)
{
    int result = 0;

    result = (n % 10) * 1000 + (n / 10);

    return result;
}

string solution(int a, int b)
{
    string result;
    bool check[10000] = {false};
    queue<reg> q;

    reg tmp(a);
    q.push(tmp);

    while (!q.empty())
    {
        reg front = q.front();
        q.pop();

        if (front.n == b)
        {
            result = front.command;
            break;
        }

        int next_n = -1;

        next_n = D(front.n);
        if (!check[next_n])
        {
            check[next_n] = true;
            q.push(reg(next_n, front.command + "D"));
        }

        next_n = S(front.n);
        if (!check[next_n])
        {
            check[next_n] = true;
            q.push(reg(next_n, front.command + "S"));
        }

        next_n = L(front.n);
        if (!check[next_n])
        {
            check[next_n] = true;
            q.push(reg(next_n, front.command + "L"));
        }

        next_n = R(front.n);
        if (!check[next_n])
        {
            check[next_n] = true;
            q.push(reg(next_n, front.command + "R"));
        }
    }

    return result;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        string command = solution(A, B);
        printf("%s\n", command.c_str());
    }
}