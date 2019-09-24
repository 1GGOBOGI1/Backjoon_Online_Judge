#include<stdio.h>

int main(void){
      long long num;
      scanf("%lld",&num);
      while(num){
            int check = 1;
            long long copy = num, ans = 0;
            //팰린드롬 체크
            while(copy){
                  ans = ans*10 + copy%10;
                  copy = copy / 10;
            }
            if(ans != num)check = 0;

            if(check){
                  //팰린드롬 맞으면 소수 체크
                  for(long long i=2;i<num;i++){
                        if(num%i==0){
                              check = 0;
                              break;
                        }
                  }
            }

            if(check){
                  printf("%lld",num);
                  break;
            }
            else num++;
      }
}