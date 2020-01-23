#include <iostream>
using namespace std;

int main()
{
    int N;
    double sum = 0, max = -1;
    cin >> N;

    double score[N];

    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
        if(max < score[i])
            max = score[i];
    }

    for (int i = 0; i < N;i++)
    {
        sum += score[i] / max * 100;
    }

    cout << sum / N;
}