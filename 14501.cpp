#include <iostream>
using namespace std;

int N;
int work[16][2], pay[16] = {0};

void day(int d)
{
    cout << "\n\nday " << d << endl;
    if (d > N)
        return;

    pay[d] = pay[d - 1];

    if (d + work[d][0] - 1 > N)
    {
        if (pay[N] < pay[d])
            pay[N] = pay[d];
        return;
    }
    day(d + 1);
    for (int i = d; i < d + work[d][0]; i++)
        pay[i] = pay[i - 1] + work[d][1];
    day(d + work[d][0] - 1);
}

int main()
{

    cin >> N;
    for (int i = 1; i < N + 1; i++)
        cin >> work[i][0] >> work[i][1];
    day(1);
    cout << pay[N];
}