#include<iostream>
using namespace std;

int find_answer(int a, int b);

int main(){
  int T;
  cin>>T;
  int ans = 0;
  for(int i=0;i<T;i++){
    int K;
    cin>>K;
    int page[K];
    int d[K-1];
    for(int j=0;j<K;j++)cin>>page[j];

    for(int j=0;j<K-1;j++){

    }

  }
}

int find_answer(int a, int b){
  if(b == a+1) return a+b;
  else{
    int tmp[b-a];
    for(int count = 0;count<b-a;count++)tmp[0]=find_answer(count,count+1);
  }
}
