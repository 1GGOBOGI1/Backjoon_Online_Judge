#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;


void makeGraph(int V, int M, vector<int> *g)
{
	int x, y;
	for (int i = 0; i < M;i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	// 정점 번호가 작은 것을 먼저 방문하기 때문에 정점 번호 순 오름차순 정렬
	for (int i = 1; i < V + 1;i++)
		sort(g[i].begin(), g[i].end());

}

void dfs(int v, vector<int> *g, bool *check)
{
	check[v] = true;
	cout << v << " ";

	for (int i = 0; i < g[v].size();i++)
	{
		int next = g[v][i];
		if(!check[next])
			dfs(next, g, check);
	}
	return;
}

void bfs(int v, vector<int> *g, bool *check)
{
	queue<int> q;
	check[v] = true;
	q.push(v);

	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 0; i < g[now].size();i++)
		{
			int next = g[now][i];
			if(!check[next])
			{
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	int N, M, V;
	// N = 정점의 개수, M = 간선의 개수, V = 탐색을 시작할 정점의 번호
	cin >> N >> M >> V;

	vector<int> g[N + 1];

	makeGraph(N, M, g);

	bool check[N + 1];
	memset(check, 0, sizeof(check));
	dfs(V, g, check);

	cout << "\n";

	memset(check, 0, sizeof(check));
	bfs(V, g, check);
}
