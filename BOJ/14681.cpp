#include <iostream>
using namespace std;

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    if(x > 0 && y > 0)
        cout<<1;
    else if(x>0&&y<0)
        cout<<4;
    else if(x<0 && y > 0)
        cout<<2;
    else if(x<0 && y <0)
        cout<<3;
}