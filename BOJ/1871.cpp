#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool calculate(string front, string back)
{
    int result = abs(((front[0] - 'A') * pow(26, 2) + (front[1]-'A') * pow(26, 1) + (front[2]-'A') * pow(26, 0)) - stoi(back));
    
    if(result <= 100)
        return true;
    else
    {
        return false;
    }
    
}


int main()
{
    int N;
    scanf("%d", &N);

    while(N--)
    {
        string input;
        cin >> input;

        string front = input.substr(0, 3);
        string back = input.substr(4);

        if(calculate(front, back))
            printf("nice\n");
        else
        {
            printf("not nice\n");
        }
        
    }
}