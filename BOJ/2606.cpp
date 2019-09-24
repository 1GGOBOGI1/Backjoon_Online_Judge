#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>a[501];
bool visit[501] = { 0 };
void dfs(int x);

int main() {
	int n,m,count=0;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	for (int i = 2;i <= n;i++) {
		if (visit[i] == true)count++;
	}
	cout << count << endl;
}

void dfs(int x){
	visit[x] = true;
	for (int i = 0;i < a[x].size();i++) {
		int next = a[x][i];
		if (visit[next]==false) dfs(next);
	}
}