#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct block
{
    //벽돌의 정보 저장
    //s = 밑면 넓이, h= 벽돌 높이, w = 무게, index = 벽돌 번호
    int s, h, w, index;
};

bool cmp(const block &b1, const block &b2)
{
    //벽돌의 넓이 기준 오름차순 정렬(넓이가 같은 벽돌은 없음)
    if (b1.s < b2.s)
        return true;
    else
        return false;
}

int main()
{
    int num; //벽돌의 개수
    cin >> num;

    block blocks[num + 1]; //벽돌 구조체의 배열

    for (int i = 1; i < num + 1; i++)
    {
        blocks[i].index = i; //받는 순서가 벽돌의 번호가 됨
        cin >> blocks[i].s >> blocks[i].h >> blocks[i].w;
    }

    //벽돌들의 넓이를 기준으로 오름차순 정렬
    sort(blocks + 1, blocks + num + 1, cmp);

    //각 벽돌을 이용했을 때의 최대 높이를 저장하는 DP배열
    int DP[num + 1] = {0};

    //각 벽돌을 이용하여 최대 높이를 만들었을 때
    //사용한 모든 벽돌의 번호를 저장하는 DP_index 벡터
    vector<vector<int>> DP_index(num + 1);

    for (int i = 1; i < num + 1; i++)
    {
        //자신의 벽돌을 이용하기 때문에 기본적으로 자기 벽돌 높이가 DP에 들어감
        DP[i] = blocks[i].h;

        int max_index = 0;
        //자기 벽돌 위에 올릴 애들을 찾음
        for (int j = i - 1; j >= 0; j--)
        {
            if ((DP[max_index] <= DP[j]) && (blocks[j].w < blocks[i].w))
                max_index = j;
        }

        if (max_index != 0) //자기 벽돌 위에 뭔가를 올릴 수 있으면
        {
            //높이를 update
            DP[i] += DP[max_index];
            //올리는 애들의 벽돌 번호를 가져옴
            DP_index[i].assign(DP_index[max_index].begin(), DP_index[max_index].end());
        }
        //자신의 벽돌 번호를 마지막에 넣음
        DP_index[i].push_back(blocks[i].index);
    }

    //max DP[n]의 index 찾기
    //max_element -> 해당 구간 내에서 최댓값의 iterator 반환
    //distance -> 두 iterator 사이의 거리를 구함(DP의 base iterator를 이용해 index 찾을 수 있음)
    int n = distance(DP, max_element(DP, DP + num + 1));

    //DP[n]에서 쓰인 벽돌의 개수 반환
    cout << DP_index[n].size() << endl;

    //DP[n]에서 쓰인 벽돌의 번호 반환
    for (auto iter = DP_index[n].begin(); iter != DP_index[n].end(); iter++)
        cout << *(iter) << endl;
}

