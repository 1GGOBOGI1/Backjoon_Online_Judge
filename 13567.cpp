#include <iostream>
#include<string>
using namespace std;

int main(){
        int M,n;
        cin>>M>>n;

        int dir = 0, x1=0,x2=0,y1=0,y2=0;

        while(n--) {
            string str;
            int num;
            cin>>str>>num;

            if(str.compare("MOVE")==0){
              switch(abs(dir%4)){
                case 0:
                  x1 += num;
                  break;
                case 1:
                  y1 += num;
                  break;
                case 2:
                  x2 += num;
                  break;
                case 3:
                  y2 += num;
                  break;
              }
            }
            else{
              if(num){
                if(dir==0)dir = 3;
                else dir--;
              }
              else dir++;
            }
              if(x1-x2<0||x1-x2>M||y1-y2<0||y1-y2>M){
                cout<<-1<<endl;
                return 0;
              }
        }
        if(x1-x2<0||x1-x2>M||y1-y2<0||y1-y2>M)cout<<-1<<endl;
        else cout<<x1-x2<<" "<<y1-y2<<endl;
}
