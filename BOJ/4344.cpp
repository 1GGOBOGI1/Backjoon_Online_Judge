#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int C,N;
    cin >> C;

    while(C--)
    {
        int N,sum = 0;
        cin >> N;

        int student[N];
        for (int i = 0; i < N;i++)
        {
            cin >> student[i];
            sum += student[i];
        }

        double avg = round(((double)sum / N) * 1000)/1000;

        int total = 0;
        for (int i = 0; i < N; i++)
            if (student[i] > avg)
                total++;
        
        double ans = round(((double)total / N * 100) * 1000) / 1000;
        cout << fixed;
        cout.precision(3);
        cout << ans << "%\n";
    }
}