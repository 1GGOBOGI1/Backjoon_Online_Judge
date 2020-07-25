#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> perm(N);

    for(int i = 0; i < N; i++)
        scanf("%d", &perm[i]);

    if(next_permutation(perm.begin(), perm.end()))
    {
        for(int i = 0; i < N; i++)
            printf("%d ", perm[i]);
    }
    else
        printf("%d", -1);
}