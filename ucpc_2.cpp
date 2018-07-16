#include<iostream>
#include<algorithm>
using namespace std;

long long card[1001];

int main() {
	long long n, m, total = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> card[i];

	while(m){
		long long tmp;
		sort(card,card+n);
		tmp = card[0]+card[1];
		card[0]=tmp;
		card[1]=tmp;
		m--;
		tmp = 0;
	}
	for (int i = 0; i < n; i++)total += card[i];
	cout << total;
	return 0;
}
