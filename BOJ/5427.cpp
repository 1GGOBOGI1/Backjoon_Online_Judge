#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int w, h;
        cin >> w >> h;

        vector<string> building[h];
        for (int i = 0; i < h; i++)
        {
            vector<int> floor(w, 0);
            string input = "";
            cin >> input;
            for (int j = 0; j < w; j++)
            {
            }
            building[i] = floor;
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                cout << building[i][j] << " ";
            cout << "\n";
        }
    }
}