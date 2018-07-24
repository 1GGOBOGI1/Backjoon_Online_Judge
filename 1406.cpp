#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<char> left, right;
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++)
		left.push(s[i]);

	int N;
	cin >> N;
	while (N--) {
		char command;
		cin >> command;
		if (command == 'L' && !left.empty()) {
			right.push(left.top());
			left.pop();
		}
		else if (command == 'D' && !right.empty()) {
			left.push(right.top());
			right.pop();
		}
		else if (command == 'B' && !left.empty()) {
			left.pop();
		}
		else if (command == 'P') {
			char c;
			cin >> c;
			left.push(c);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	
	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}

	return 0;
}