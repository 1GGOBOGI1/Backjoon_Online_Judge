#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void) {
	stack <char> pip;
	stack <char> check;
	string test;
	int ans = 0;
	getline(cin, test);
	for (int i = 0;i<test.length();i++) {
		if (check.empty()) {
			if (test[i] == '(')check.push('(');
			else if (test[i] == ')') {
				ans++;
				pip.pop();
			}
		}
		else {
			if (test[i] == '(') {
				pip.push('(');
			}
			else if (test[i] == ')') {
				check.pop();
				ans = ans + pip.size();
			}
		}
	}
	printf("%d", ans);
}
