#include <iostream>
#include <vector>
using namespace std;

int makeSequence(vector<int> &sequence)
{
    int index = 0;
    int maxValue = 0;

    while(true)
    {
        if(maxValue < sequence[index])
            maxValue = sequence[index];

        if(sequence[index] == 1)
            return maxValue;

        if(sequence[index] % 2 == 0)
        {
            sequence.push_back(sequence[index]/2);
        }
        else
        {
            sequence.push_back(sequence[index]*3 +1);
        }
        index++;
    }

    return maxValue;
}

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)  
    {
        int n;
        scanf("%d", &n);

        vector<int> sequence;
        sequence.push_back(n);

        printf("%d\n", makeSequence(sequence));
    }
}