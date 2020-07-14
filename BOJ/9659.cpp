#include <iostream>
using namespace std;

int main()
{
    long long N;
    scanf("%lld", &N);

    bool isSkLast = true;

    long long turn = N / 3;
    long long last = N % 3;

    isSkLast = turn % 2 == 1 ? true : false;
    
    if(last %2 == 1)
        isSkLast = !isSkLast;
    
    if(isSkLast)
        printf("SK");
    else
        printf("CY");
}