#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<bitset<26>> dic;
int N;
long long ans = 0;

void DFS(int cnt, bitset<26> alphabet)
{
    if(cnt == N)
    {
        if(alphabet.any())
            return;
        
        ans++;
        return;
    }

    DFS(cnt+1, alphabet & dic[cnt]);
    DFS(cnt+1,alphabet);
}

bool check(int bitmask)
{
    bitset<26> alphabet;
    alphabet.set();

    for(int i = 0; i < dic.size(); i++)
    {
        if(bitmask & (1<<i))
        {
            alphabet &= dic[i];
        }
    }

    if(alphabet.any())
        return false;

    return true;
}

bitset<26> makeBit(string input)
{
    bitset<26> bit;
    bit.set();

    for(int i = 0; i < input.length(); i++)
    {
        int location = input[i] - 'a';

        if(bit.test(location))
        {
            bit.set(location,0);
        }
    }

    return bit;
}

int main()
{
    scanf("%d", &N);
    string input;
    for(int i = 0; i < N; i++)
    {
        cin>>input;
        dic.push_back(makeBit((input)));
    }

    bitset<26> alphabet;
    alphabet.set();

    DFS(0,alphabet);

    printf("%lld", ans);
}