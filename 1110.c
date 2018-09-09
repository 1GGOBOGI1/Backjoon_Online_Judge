#include<stdio.h>

int main(void){
      int input, count = 0, prev = -999, compare = -999;
      scanf("%d",&input);
      prev = input;
      while(input != compare){
            count++;
            compare = (prev%10)*10 + (prev/10 + prev%10)%10;
            prev = compare;
      }
      printf("%d",count);
}