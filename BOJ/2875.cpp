#include <iostream>
using namespace std;

int main()
{
    int N, M, K, ans = 0;
    cin >> N >> M >> K;
    int n = N / 2;

    if (n > M) //남자 2명 그룹 수가 여자 전체 수 보다 작은 경우
        n = M;
    if (K <= (N - n * 2) + (M - n)) //나머지 사람이 K보다 많은거나 같은 경우
        cout << n;
    else //나머지 사람이 K보다 적은 경우 -> 팀 해체해야함
    {
        if ((K - ((N - n * 2) + (M - n))) % 3)
            cout << n - (K - ((N - n * 2) + (M - n))) / 3 - 1;
        else
            cout << n - (K - ((N - n * 2) + (M - n))) / 3;
    }
}