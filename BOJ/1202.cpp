#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
using namespace std;

bool compare(const pair<int, int> &v1, const pair<int, int> &v2)
{
    //가격이 많이 나가는 애가 앞으로
    //가격이 같다면 무게가 많이 나가는 애가 앞으로
    if (v1.second == v2.second)
        return v1.first > v2.first;
    return v1.second > v2.second;
}

int main()
{
    vector<pair<int, int>> dia(300000); //<무게, 가격>
    multiset<int> bag;                  //insert할때 자동정렬하면서 시간 줄이려고 multiset 사용
    int N, K, tmp;
    unsigned int ans = 0;

    scanf("%d %d", &N, &K); //scanfㅠㅠ...scanf도 썼는데...!

    for (int i = 0; i < N; i++)
        scanf("%d %d", &dia[i].first, &dia[i].second);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &tmp);
        bag.insert(tmp);
    }

    sort(dia.begin(), dia.end(), compare); //가격 많이 나가는 놈부터 찾으려고 sort

    for (int i = 0; (i < N) && (K > 0); i++)
    {
        //현재 보석 무게보다 같거나 큰 수 중 가장 작은 수를 가진 가방 무게 주소 찾음
        auto addr = lower_bound(bag.begin(), bag.end(), dia[i].first);
        //lower_bound에 해당하는 값이 없으면 addr = bag.end()되니까 거름
        if (addr != bag.end())
        {
            ans += dia[i].second;
            bag.erase(addr);
            K--;
        }
    }
    printf("%d", ans);
}