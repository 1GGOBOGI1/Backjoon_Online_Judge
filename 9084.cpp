#include<iostream>
#include<string>
using namespace std;

int test[21];

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int N;
		int num=0;
		
		cin>>N;
		string test_case;
		getline(cin,test_case);
		for(int j=0,k=0;j<test_case.length();j++){
			if(test_case[i]==' '){
				test[k]=num;
				k++;
				num=0;
			}
			else{
				num=num*10+test_case[i];
			}
		}
		for(int j=0;j<N;j++)cout<<test[j];
	}
}