#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;
int main(){
  int num;
  int score=0;
  cin >> num;
  for(int i=0;i<num;i++){
    int k;
    cin>>k;
    a[i]=k;
  }
  vector<int>::iterator A = a.begin();
  sort(A,A+num);
  for(int i = 0 ;a.size()>1;i=i+2){
    int first = a[num-i-1];
    a.pop_back();
    int second = a[num-i-2];
    a.pop_back();
    score = score + first*second;
  }
  cout<<score;

}
