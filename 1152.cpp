#include<iostream>
#include<string>
using namespace std;

int main(){
      string input;
      getline(cin,input);
      int ans = 0;
      if(input!=""){
            for(int i=0;i<input.size();i++){
                  if(input[i]!=' '){
                        if(i==0)ans++;
                        else if(input[i-1]==' ')ans++;
                  }
            }
      }
      cout<<ans;
}