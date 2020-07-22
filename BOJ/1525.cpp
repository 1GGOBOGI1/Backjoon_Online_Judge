#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int solution(string num)
{
    map<string, int> m;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    queue<string> q;
    q.push(num);
    m[num] = 0;

    while (!q.empty())
    {
        string front = q.front();
        q.pop();

        if (front == "123456780")
            break;

        int index = front.find('0');

        int x = index % 3;
        int y = index / 3;
        for (int i = 0; i < 4; i++)
        {
            string next = front;
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            int next_index = next_x + next_y * 3;

            if (0 <= next_x && next_x <= 2 && 0 <= next_y && next_y <= 2)
            {
                swap(next[index], next[next_index]);

                //cout << front_str << "\n";
                if (m.count(next) == 0)
                {
                    q.push(next);
                    m[next] = m[front] + 1;
                }

                swap(next[index], next[next_index]);
            }
        }
    }

    return m.count("123456780") ? m["123456780"] : -1;
}

int main()
{
    int input = 0;
    int tmp;

    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &tmp);

        input = input * 10 + tmp;
    }

    printf("%d", solution(to_string(input)));
}