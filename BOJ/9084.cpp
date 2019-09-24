#include <iostream>
#include <string>
using namespace std;

int test[21];

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		int num = 0;
		cout << "T" << endl;
		cin >> N;
		fflush(stdin);
		string test_case;
		getline(cin, test_case);
		for (int j = 0, k = 0; j < test_case.length()+1; j++)
		{
			if(j==test_case.length()){
				test[k]=num;
			}
			if (test_case[j] == ' ')
			{
				test[k] = num;
				k++;
				num = 0;
			}
			else
			{
				num = num * 10 + (test_case[j]-'0');
			}
		}
		
	}
}