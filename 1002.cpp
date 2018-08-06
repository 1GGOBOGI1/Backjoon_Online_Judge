#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
      int T;
      cin>>T;
      for(long long i=0;i<T;i++){
            int x1,y1,r1,x2,y2,r2;
            

            long long distance = sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));

            if(x1==x2&&y1==y2){
                  if(r1==r2)printf("-1\n");
                  else printf("0\n");
            }
            else{
                  if((r1+r2)>distance&&abs(r1-r2)<distance)printf("2\n");
                  else if((r1+r2)==distance||abs(r1-r2)==distance)printf("1\n");
                  else printf("0\n");
            }
      }
}