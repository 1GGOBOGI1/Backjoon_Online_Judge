#include<stdio.h>
#include<math.h>

int main(void){
      int A,B,x,y;
      scanf("%d %d",&A, &B);
      x = A/B; y = A%B;
      printf("%llf",(long long)A/B);
      return 0;
}