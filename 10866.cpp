#include<iostream>
#include<deque>
#include<string>
using namespace std;

deque<int>deq;

int main(){
      int num;
      cin>>num;
      for(int i=0;i<num;i++){
            string a;
            cin>>a;
            if(a == "push_front"){
                  int x;
                  cin>>x;
                  deq.push_front(x);
            }
            else if(a=="push_back"){
                  int x;
                  cin>>x;
                  deq.push_back(x);
            }
            else if(a == "pop_front"){
                  if(deq.empty())cout<<-1<<endl;
                  else{
                        int x = deq.front();
                        cout<<x<<endl;
                        deq.pop_front();
                  }
                  
            }
            else if(a=="pop_back"){
                  if(deq.empty())cout<<-1<<endl;
                  else{
                        int x = deq.back();
                        cout<<x<<endl;
                        deq.pop_back();
                  }
                  
            }
            else if(a=="size"){
                  cout<<deq.size()<<endl;
            }
            else if(a=="empty"){
                  if(deq.empty())cout<<1<<endl;
                  else cout<<0<<endl;
            }
            else if(a=="front"){
                  if(deq.empty())cout<<-1<<endl;
                  else{
                        int x = deq.front();
                        cout<<x<<endl;
                  }
                  
            }
            else if(a=="back"){
                  if(deq.empty())cout<<-1<<endl;
                  else{
                        int x = deq.back();
                        cout<<x<<endl;
                  }
                  
            }
      }
}