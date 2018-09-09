#include<stdio.h>

char room[10001];

int main(void){
      int num;
      scanf("%d", &num);
      for(int i=0;i<num;i++){
            for(int j=0;j<num;j++)scanf("%c",&room[i*num+j]);
            fflush(stdin);
      }
      for(int i=0;i<num;i++){
            for(int j=0;j<num;j++)printf("%c",room[i*num+j]);
            printf("\n");
      }
      printf("room[num-1] = %c\n",room[num-1]);
}