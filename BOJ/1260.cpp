#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>a[1001];
bool visit[1001] = { 0 };
vector<int>dfs_answer1;
vector<int>bfs_answer];
void dfs(int x);

int main() {
	int N,M,V;
      cin>>N>>M>>V;
	for (int i = 0;i < M;i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(V);
}

void dfs(int x){
	visit[x] = true;
      dfs_answer1.push_back(x);
	for (int i = 0;i < a[x].size();i++) {
		int next = a[x][i];
		if (visit[next]==false) dfs(next);
	}
}

