#include<iostream>
#include<algorithm>
using namespace std;

long long num[1000002]={0,1,1,1,};

int main(){
      long long input;
      cin>>input;
      for(long long i=4;i<=input;i++){
            num[i] = num[i-1]+1;
            if(i%2==0 && num[i]>num[i/2]+1)num[i] = num[i/2]+1;
            if(i%3==0 && num[i]>num[i/3]+1)num[i] = num[i/3]+1;
      }
      cout<<num[input];
}