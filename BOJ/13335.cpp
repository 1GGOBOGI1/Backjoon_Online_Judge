#include<iostream>
#include<deque>
using namespace std;

int main(){
  int n,w,L;
  int done = 0;
  int next = 1;
  cin>>n>>w>>L;
  int car[n]={0};
  int count[n]={0};
  int ans = 0;
  deque<int>bridge;
  for(int i=0;i<n;i++){
    cin>>car[i];
  }
  bridge.push_back(0);
  while(!bridge.empty()){
    ans++;
    int weight = 0;
    for(int i=0;i<bridge.size();i++){
      count[bridge[i]]++;
    }

    if(count[bridge.front()]>w){
      bridge.pop_front();
      done++;
      if(done == n )break;
    }
    for(int i=0;i<bridge.size();i++)weight+=car[bridge[i]];
    if(!(bridge.size()+done>n)){
      if(weight+car[next]<=L){
        count[next]++;
        bridge.push_back(next);
        next++;
      }
    }
  }
  cout<<ans;
}
