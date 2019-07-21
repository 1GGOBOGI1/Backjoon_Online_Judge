#include <iostream>
#include <vector>
using namespace std;

bool checkarr(int arr[], int n)
{
    int cnt[n] = {0};

    for (int i = 0; i < n; i++)
        cnt[arr[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] != arr[i])
            return false;
    }
    return true;
}

void rperm(int arr[], int len, int n)
{
    if (len == n)
    {
        if (checkarr(arr, n))
        {
            for (int i = 0; i < n; i++)
            {
                if(i!=0)
                    cout << ", ";
                cout << arr[i];
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        arr[len] = i;
        rperm(arr, len + 1, n);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    rperm(arr, 0, n);
}