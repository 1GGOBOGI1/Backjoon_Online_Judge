#include <iostream>
using namespace std;

int main()
{
    int K;
    cin >> K;

    int A[46] = {0};
    int B[46] = {0};

    A[2] = 1;
    A[3] = 1;
    B[1] = 1;
    B[2] = 1;

    for (int i = 3; i <= K;i++)
    {
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }

    cout << A[K] << " " << B[K] << "\n";
}