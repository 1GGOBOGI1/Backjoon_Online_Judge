#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < M;i++)
        {
            int x, y;
            cin >> x >> y;
        }
        cout << N - 1 << "\n";
    }
}