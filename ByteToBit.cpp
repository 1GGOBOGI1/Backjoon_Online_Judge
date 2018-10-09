#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
    int N;
    cin>>N;
    int a = N/26;
    int b = N%26-1;
    cout<<a<<" "<<b<<endl;
    if(b>0 && b<=2)cout<<1*pow(2,a)<<" "<<0<<" "<<0<<endl;
    else if(b>2&&b<=8)cout<<0<<" "<<1*pow(2,a)<<" "<<0<<endl;
    else cout<<0<<" "<<0<<" "<<1*pow(2,a);
  }
}
