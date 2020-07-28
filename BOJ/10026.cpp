#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int i, int j, int N,vector<vector<bool>> &check, vector<string> &picture, bool blindness)
{
    stack<pair<int,int>> s;

    check[i][j] = true;
    s.push(make_pair(i,j));

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while(!s.empty())
    {
        int x = s.top().first;
        int y = s.top().second;
        s.pop();

        for(int i = 0; i < 4; i++)
        {
            int next_x = x+dx[i];
            int next_y = y+dy[i];

            if(0<=next_x && next_x < N && 0 <= next_y && next_y < N)
            {
                if(!check[next_x][next_y])
                {
                    // 적록색약인 경우
                    if(blindness)
                    {
                        // B-B, !B - !B
                        if((picture[x][y] == 'B' && picture[next_x][next_y] == 'B') || (picture[x][y] != 'B' && picture[next_x][next_y] != 'B'))
                        {
                            check[next_x][next_y] = true;
                            s.push(make_pair(next_x, next_y));
                            s.push(make_pair(x,y));
                        }
                    }
                    else
                    {
                        if(picture[x][y] == picture[next_x][next_y])
                        {
                            check[next_x][next_y] = true;
                            s.push(make_pair(next_x, next_y));
                            s.push(make_pair(x,y));
                        }
                    }
                }
            }
        }
    }
}

pair<int,int> solution(vector<string> &picture, int N)
{
    pair<int,int> ans = make_pair(0,0);

    vector<vector<bool>> check(N,vector<bool>(N,false));

    for(int i = 0; i <N; i++)
        for(int j = 0; j < N; j++)
            if(!check[i][j])
            {
                ans.first++;
                DFS(i,j,N,check,picture,false);
            }

    vector<vector<bool>> check2(N, vector<bool>(N, false));

    for(int i = 0; i <N; i++)
        for(int j = 0; j < N; j++)
            if(!check2[i][j])
            {
                ans.second++;
                DFS(i,j,N,check2,picture,true);
            }

    return ans;
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<string> picture;

    string input;

    for(int i = 0; i < N; i++)
    {
        cin>>input;
        picture.push_back(input);
    }

    pair<int,int> ans = solution(picture, N);
    printf("%d %d", ans.first, ans.second);
}