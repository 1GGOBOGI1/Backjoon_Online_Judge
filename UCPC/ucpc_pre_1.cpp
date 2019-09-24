#include<iostream>
#include<vector>
using namespace std;

struct OptimizeUnionFind
{
    vector<int> parent;
    OptimizeUnionFind(int n):parent(6)
    {
        for (int i = 1; i < n+1;i++)
            parent[i] = i;
    }

    int Find(int a)
    {
        if(a == parent[a])
            return a;

        return Find(parent[a]);
    }

    void merge(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if(a==b)
            return;

        if(a<b)
            swap(a, b);

        parent[a] = b;

        return;
    }
};

int main()
{
    int N;
    bool ans[3] = {false};
    cin >> N;
    // OptimizeUnionFind MST(5);
    // for (int i = 0; i < N;i++)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     MST.merge(a, b);
    // }

    // // cout << MST.Find(1) << MST.Find(2) << MST.Find(3) << MST.Find(4) << MST.Find(5) << endl;
    // if(MST.Find(1)==1&&MST.Find(3)==1&&MST.Find(4)==1&&MST.Find(2)==2&&MST.Find(5)==5)
    //     cout << "Wa-pa-pa-pa-pa-pa-pow!";
    // else
    // {
    //     cout << "Woof-meow-tweet-squeek" ;
    // }

    if(N!=3)
    {
        cout << "Woof-meow-tweet-squeek";
        return 0;
    }
    else
    {
        for (int i = 0; i < 3;i++)
        {
            int a, b;
            cin >> a >> b;
            if(a>b)
                swap(a, b);
            if(a==1&&b==3)
                ans[0] = true;
            else if(a==1&&b==4)
                ans[1] = true;
            else if(a==3&&b==4)
                ans[2] = true;
        }

        for (int i = 0; i < 3;i++)
        {
            if(ans[i]==false)
            {
                cout << "Woof-meow-tweet-squeek";
                return 0;
            }
        }
        cout << "Wa-pa-pa-pa-pa-pa-pow!";
    }
    
    
}