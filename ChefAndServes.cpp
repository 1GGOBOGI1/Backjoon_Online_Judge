#include<iostream>
using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
    long long int p1,p2,k;
    cin>>p1>>p2>>k;
    if(((p1+p2)/k)%2)cout<<"COOK"<<endl;
    else cout<<"CHEF"<<endl;
  }
}
