#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
using namespace std;

int main(){
      int tmp=0,all[50],num=0;
      stack<int> first;
      queue<int> second;
      string test_case;
      getline(cin,test_case);
      while(test_case!="0"){
            for(int i=2;i<test_case.length()+1;i++){
                  if(i==test_case.length()){
                        cout<<tmp<<endl;
                        all[num++]=tmp;
                  }
                  if(test_case[i]!=' '){
                        tmp = tmp*10 + (test_case[i]-'0');
                  }
                  else{
                        all[num++]=tmp;
                        tmp = 0;
                  }
            }
            sort(all,all+num);
            for(int i=5;i<0;i--){
                  for(int j=0;j<num;j++){
                        if(j<i)first.push(all[i]);
                        else second.push(all[i]);
                  }
                  for(;second.size();){
                        for(int j=0;j<6;j++){
                              if(j<i){
                                    cout<<first[i];
                                    first.push(first.front());
                                    first.pop();
                              }
                              else if(j==)
                              else{
                                    cout<<second.top();
                                    first.push(second.top());
                                    second.pop();
                              }
                        }
                  }

            }

            getline(cin,test_case);
      }
}