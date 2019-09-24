#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int>room(N);
    for (int i = 0; i < N;i++)
        scanf("%d", &room[i]);

    while(M--){
        int now, ans = 0;
        scanf("%d", &now);
        if (now == 0)
        {
            vector<int>::iterator iter = room.begin();
            while(iter != room.end()){
                iter = find(iter, room.end(), 1);
                if(iter==room.end())
                    break;
                ans++;
                while (iter == room.end() || *(iter++) != 0){}
            }
            printf("%d\n", ans);
        }
        else{
            int num;
            scanf("%d", &num);
            room[num] = 1;
        }
    }
}