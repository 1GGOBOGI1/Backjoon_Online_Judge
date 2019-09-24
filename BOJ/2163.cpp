#include<iostream>
using namespace std;
void answer(int N,int M);

int ans=0;

int main(){
  int N,M;
  cin>>N>>M;
  answer(N,M);
  cout<<ans;
}

void answer(int N,int M){
  if(N==1&&M==1)return ;
  ans++;
  if(N>M){
    answer(N/2,M);
    answer(N/2+N%2,M);
  }
  else{
    answer(N,M/2);
    answer(N,M/2+M%2);
  }
}
