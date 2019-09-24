#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int fibonacci(int n, int zero, int one);

int main(void){
      int T;
      scanf("%d",&T);
      while(T--){
            int num, count[41][2]={0};
            count[0][0]=1;
            count[1][1]=1;
            scanf("%d",&num);
            for(int i=2;i<=num;i++){
                  count[i][0]=count[i-1][0]+count[i-2][0];
                  count[i][1]=count[i-1][1]+count[i-2][1];
            }
            printf("%d %d\n",count[num][0],count[num][1]);
            
      }
}