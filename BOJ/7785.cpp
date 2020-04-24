#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    set<string> office;

    string name, state;
    while (n--)
    {
        cin >> name >> state;

        if(state == "enter")
            office.insert(name);
        else if(state == "leave")
            office.erase(office.find(name));
    }

    for (auto iter = office.rbegin(); iter != office.rend(); iter++)
        cout << *iter << "\n";
}