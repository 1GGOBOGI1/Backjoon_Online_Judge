#include<iostream>
using namespace std;

int main(){
      long long total=0, answer=1;
      int num,now_one=0;;
      cin>>num;
      int min_zero = num/2;
      num = num-1;
      for(;num>=min_zero;num--){
            int copy_num = num;
            for(int i=now_one;i>0;i--){
                  answer=answer*copy_num;
                  copy_num = copy_num -1;
            }
            total = total + answer;
            answer = 1;
            now_one = now_one +1;
      }
      cout<<total;
}