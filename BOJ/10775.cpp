#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> gate, rank;
    int num;

    UnionFind(int n) : gate(n+1), rank(n+1,1)
    {
        num = 0;

        for (int i = 0; i <= n; i++)
        {
            gate[i] = i;
        }
    }

    int find(int n)
    {
        if(n == gate[n])
            return n;

        return gate[n] = find(gate[n]);
    }

    int docking(int i)
    {
        int flag;
        do
        {
            flag = find(i);
            i = i - 1;
            if(i < 0)
                break;
        } while (flag == 0);

        if(flag == 0)
        {
            //cout << "fail to docking\n";
            return -1;
        }
        else
        {
            //cout << "gate " << i+1 << " is open\n";
            gate[i+1] = 0;
            num++;
            return 0;
        }
    }

    int numOfPlanes()
    {
        return num;
    }
};

int main()
{
    int G, P, input;

    UnionFind uf(G);

    cin >> G >> P;

    for (int i = 0; i < P;i++)
    {
        cin >> input;
        if(uf.docking(input) == -1)
        {
            //cout << "airport closed!";
            cout << uf.numOfPlanes();
            return 0;
        }
    }

    cout << uf.numOfPlanes();
}