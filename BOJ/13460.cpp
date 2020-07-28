#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M;
int min_move = 11;

struct position
{
    int x, y;
    position(int _x, int _y) : x(_x), y(_y) {}
};

struct marble
{
    position red;
    position blue;

    marble(int x1, int y1, int x2, int y2) : red(position(x1, y1)), blue(position(x2, y2)) {}

    void setRed(int x, int y)
    {
        red = position(x, y);
    }

    void setBlue(int x, int y)
    {
        blue = position(x, y);
    }
};

struct cmp
{
    bool operator()(const marble a, const marble b) const
    {
        return a.red.x > a.red.y;
    }
};

// 파란색 먼저: -1, 상관없음: 0, 빨간색 먼저: 1
int setMoveSequence(marble m, char direction)
{
    // 파란색이나 빨간색을 먼저 움직여야 할 경우를 걸러냄
    switch (direction)
    {
    case 'l':
        if (m.red.x == m.blue.x)
        {
            if (m.blue.y < m.red.y)
                return -1;
            else
                return 1;
        }
        break;

    case 'r':
        if (m.red.x == m.blue.x)
        {
            if (m.blue.y > m.red.y)
                return -1;
            else
                return 1;
        }
        break;

    case 'u':
        if (m.red.y == m.blue.y)
        {
            if (m.blue.x < m.red.x)
                return -1;
            else
                return 1;
        }
        break;

    case 'd':
        if (m.red.y == m.blue.y)
        {
            if (m.blue.x > m.red.x)
                return -1;
            else
                return 1;
        }
        break;
    }

    return 0;
}

pair<int, marble> getNewPosition(vector<string> &board, marble m, char direction, int sequence)
{
    // state = 0: 계속 진행, state = 1: 성공, state = -1: 실패
    int state = 0;
    int tmp = 0;
    int x = 0, y = 0;
    if (sequence == -1) // 파란색을 먼저 움직여야 하는 경우
    {
        x = m.blue.x;
        y = m.blue.y;
    }
    else
    {
        x = m.red.x;
        y = m.red.y;
    }

    if (direction == 'l' || direction == 'r')
    {
        if (direction == 'l')
            tmp = -1;
        else
            tmp = 1;

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                if (sequence == -1)
                {
                    m.setBlue(x, y);
                    x = m.red.x;
                    y = m.red.y;
                }
                else
                {
                    m.setRed(x, y);
                    x = m.blue.x;
                    y = m.blue.y;
                }
            }

            for (; 0 <= y && 0 < M; y += tmp)
            {
                if (y + tmp < 0 || y + tmp >= M || board[x][y + tmp] == '#')
                    break;

                if(i == 1 && sequence == -1 && y+tmp == m.blue.y)
                    break;
                else if(i == 1 && sequence == 1 && y+tmp == m.red.y)
                    break;

                else if (board[x][y + tmp] == 'O')
                {
                    if ((sequence == -1 && i == 0) || (sequence == 1 && i == 1) || (sequence == 0 && i == 1))
                    {
                        state = -1;
                        y = 0;
                        break;
                    }
                    else if(state != -1)
                    {
                        state = 1;
                        y = 0;
                        break;
                    }
                }
            }
        }
    }
    else if (direction == 'u' || direction == 'd')
    {
        if (direction == 'u')
            tmp = -1;
        else
            tmp = 1;

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                if (sequence == -1)
                {
                    m.setBlue(x, y);
                    x = m.red.x;
                    y = m.red.y;
                }
                else
                {
                    m.setRed(x, y);
                    x = m.blue.x;
                    y = m.blue.y;
                }
            }

            for (; 0 <= x && 0 < N; x += tmp)
            {
                if (x + tmp < 0 || x + tmp >= N || board[x + tmp][y] == '#')
                    break;

                if(i == 1 && sequence == -1 && x+tmp == m.blue.x)
                    break;
                else if(i == 1 && sequence == 1 && x+tmp == m.red.x)
                    break;

                else if (board[x + tmp][y] == 'O')
                {
                    if ((sequence == -1 && i == 0) || (sequence == 1 && i == 1) || (sequence == 0 && i == 1))
                    {
                        state = -1;
                        x = 0;
                        break;
                    }
                    else if(state != -1)
                    {
                        state = 1;
                        x = 0;
                        break;
                    }
                }
            }
        }
    }

    if(sequence == -1)
        m.setRed(x,y);
    else
        m.setBlue(x,y);

    return make_pair(state, m);
}

string getKey(marble m) {
    string output = "";

    output += to_string(m.red.x)+to_string(m.red.y)+to_string(m.blue.x)+to_string(m.blue.y);

    return output;
}

void move(vector<string> &board, marble m, map<string, int> &history, int cnt)
{
    string key = getKey(m);
    if (cnt > 10 || (history.find(key) != history.end() && history[key] < cnt))
    {
        return;
    }

    history.insert(make_pair(key, cnt));

    char dir[] = {'l', 'r', 'u', 'd'};

    for (int i = 0; i < 4; i++)
    {
        pair<int, marble> result = getNewPosition(board, m, dir[i], setMoveSequence(m, dir[i]));

        if (result.first == -1)
            continue;
        else if (result.first == 1)
        {
            if (min_move > cnt)
                min_move = cnt;
            continue;
        }
        else
        {
            move(board, result.second, history, cnt + 1);
        }
    }
    return;
}

int solution(vector<string> &board)
{
    int ans = -1;

    map<string, int> history;

    marble m(0, 0, 0, 0);

    // 보드 재활용이 가능하도록 구슬의 위치를 기록한 뒤 .으로 바꿔 줌
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'B')
            {
                m.setBlue(i, j);
                board[i][j] = '.';
            }
            else if (board[i][j] == 'R')
            {
                m.setRed(i, j);
                board[i][j] = '.';
            }
        }

    move(board, m, history, 1);

    if (min_move != 11)
        ans = min_move;

    return ans;
}

int main()
{
    scanf("%d %d", &N, &M);

    vector<string> board;
    string input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        board.push_back(input);
    }

    printf("%d", solution(board));
}