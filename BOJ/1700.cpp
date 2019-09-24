#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> socket;
    vector<int> seq(K, 0);
    int ans = 0, input, start = -1;

    for (int i = 0; i < K; i++)
    {
        cin >> input;
        if (socket.size() < N)
        {
            auto addr = find(socket.begin(), socket.end(), input);
            if (addr == socket.end())
                socket.push_back(input);
        }
        else
        {
            if (start == -1)
                start = i;
            seq[i] = input;
        }
    }

    if (start != -1)
    {
        for (int i = start; i < K; i++)
        {
            // cout << "\ni = " << i << endl;
            auto addr = find(socket.begin(), socket.end(), seq[i]);
            if (addr == socket.end())
            {
                int max = 0, max_index = 0;
                for (int j = 0; j < N; j++)
                {
                    int tmp = find(seq.begin() + i + 1, seq.end(), socket[j]) - seq.begin() + i;
                    // cout << socket[j] << " after " << tmp << endl;
                    if (max < tmp)
                    {
                        max = tmp;
                        max_index = j;
                    }
                }
                // cout << "pop " << socket[max_index] << endl;
                socket.erase(socket.begin() + max_index);
                socket.push_back(seq[i]);
                ans++;
            }
            // cout << "inside socket" << endl;
            // for (int j = 0; j < N; j++)
            //     cout << socket[j] << " ";
            // cout << endl;
        }
    }
    cout << ans << endl;
}