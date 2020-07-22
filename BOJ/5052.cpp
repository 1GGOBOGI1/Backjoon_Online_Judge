#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    char val;
    Node *next;
};

struct Tire
{
    Node *root;
    
};

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        vector<string> dic(n);

        for (int i = 0; i < n; i++)
            cin >> dic[i];

        printf(sortDic(dic) ? "YES\n" : "NO\n");
    }
}