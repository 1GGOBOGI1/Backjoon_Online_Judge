#include<iostream>
using namespace std;

int main(){
      int A,B,a=0,b=0;
      cin>>A>>B;
      while(A){
            a = a*10 +A%10;
            A = A/10;
      }
      while(B){
            b = b*10 + B%10;
            B = B/10;
      }
      if(a>b)cout<<a;
      else cout<<b;
}