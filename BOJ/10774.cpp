#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int J, A;
    scanf("%d\n%d", &J, &A);
    
    vector<char> size(J + 1);

    for (int i = 1; i <= J; i++)
    {
        cin >> size[i];
    }

    int answer = 0;

    while (A--)
    {
        char _size;
        int num;
        cin >> _size >> num;

        if(size[num] == 'q')
            continue;

        if ((size[num] == 'S' && _size == 'S') || (size[num] == 'M' && (_size != 'L')) || (size[num] == 'L'))
        {
            answer++;
            size[num] = 'q';
        }
    }

    printf("%d", answer);
}