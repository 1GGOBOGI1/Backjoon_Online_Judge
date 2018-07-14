#include<iostream>
#include<vector>
using namespace std;

int N,r,c;
int num = 0, ans = 0;
int x = 0, y = 0;
int dx={1,-1,1},dy={0,1,0};

int main(){
  cin >> N>> r>> c;

}

void answer(int size){
  if(size==2){
    num++;
    for(int i=0;i<3;i++){
      x += dx[i]; y += dy[i];
      if(x==c&&y==r){
        cout<<num-1;
        exit(1);
      }
    }
    return ;
  }
  else{
    answer(size/2);
    if((y+1) % size){
      if((x+1) % size) x = x +1; y = y - size/2 +1;
      else y = y +1; x = x - size +1;
    }
    else{
      if((x+1) % size) x = x +1; y = y - size/2 +1;
      else x =
    }
    if(((x+1) % size) && ((y+1) % size)) x = x+1; y = y - size/2 +1;
    else if(!((x+1) % size) && ((y+1) % size))x = x - size/2 +1; y = y+1;
    else if(((x+1) % size) && !((y+1) % size))x = x+1; y =
  }
}
