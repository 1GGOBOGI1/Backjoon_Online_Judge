#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdio>
#include<deque>

using namespace std;

deque<int>card;
deque<int>com;
deque<int>answer;

int main() {
	int L, n, m;
	long long SUM = 1, DIVIDE = 1, ANS = 1, ANSWER = 1, TMP = 0,sum = 0, divide = 0, d=0,s=0,ans = 0;

	cin >> L;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int tmp;
		scanf("%d", &tmp);
		card.push_back(tmp);
	}

	fflush(stdin);
	cin >> m;
	for (int i = 0;i < m;i++) {
		int tmp;
		scanf("%d", &tmp);
		com.push_back(tmp);
	}

	while (!com.empty()) {
		if (com.front() == card.front()) {
			com.pop_front();
			card.pop_front();
		}
		else {
			if (com.front() == 1){
				card.pop_front();
				divide++;
				com.pop_front();
				card.push_front(1);
			}
			else {
				card.pop_front();
				if (card.front() == 1) {
					sum++;
					card.pop_front();
					com.pop_front();
				}
				else {
					card.pop_front();
					d++;
					card.push_front(1);
					com.pop_front();
					s++;
				}
			}
		}
	}
	ans = sum + divide+d+s;
	long long dd = d + s;

	TMP = ans;
	while (ans) {
		ANSWER = ANSWER * ans;
		ans--;
	}
	while (sum) {
		ANSWER = ANSWER / sum;
		sum--;
	}
	while (divide) {
		ANSWER = ANSWER / divide;
		divide--;
	}
	while (dd) {
		ANSWER = ANSWER / dd;
		dd--;
	}
	cout<<TMP%1000000007<<" "<< ANSWER% 1000000007;
}