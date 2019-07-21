#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void ans(int n, int page[])
{
    cout << "current n = " << n << endl;

    auto num_to_string = to_string(n);
    int num_size = num_to_string.size();

    int num_front = n / pow(10, num_size - 1);

    page[num_front] += 1;

    for (int i = 1; i <= num_front; i++)
    {
        page[i] += pow(10, num_size - 1);
    }

    if (num_size == 1)
        return;
    else
        return ans(n - num_front * pow(10, num_size - 1), page);
    cout << num_size << endl;
    cout << pow(10, num_size) << endl;
}

int main()
{
    int n;
    cin >> n;

    int page[10] = {0};

    ans(n, page);

    for (int i = 0; i < 10; i++)
        cout << page[i] << " ";
}