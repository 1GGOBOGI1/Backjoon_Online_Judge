#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void makeGraph(vector<int> *graph, vector<pair<int,int>> &nodeInfo, int V, int E)
{

      for (int i = 1; i <= V;i++)
            cin >> nodeInfo[i].first;

      for (int i = 0; i < E;i++)
      {
            int X, Y;
            cin >> X >> Y;

            graph[X].push_back(Y);
            nodeInfo[Y].second++;
      }
}


int TopologicalSort(int V, int E)
{
      vector<int> graph[V + 1];
      vector<pair<int, int>> nodeInfo(V + 1,make_pair(0,0)); // { first : time , second : indegree}
      
      makeGraph(graph, nodeInfo, V, E);

      queue<int> q;
      int spendTime[V + 1] = {0};
      int W;
      cin >> W;

      for (int i = 1; i <= V;i++)
            if(nodeInfo[i].second == 0)
            {
                  spendTime[i] = nodeInfo[i].first;
                  q.push(i);
            }

      while(!q.empty())
      {
            int now = q.front();
            q.pop();

            if(now == W)
                  break;

            for (int i = 0; i < graph[now].size();i++)
            {
                  int next = graph[now][i];
                  nodeInfo[next].second--;
                  if(spendTime[next] < spendTime[now] + nodeInfo[next].first)
                        spendTime[next] = spendTime[now] + nodeInfo[next].first;
                  if(nodeInfo[next].second == 0)
                        q.push(next);
            }
      }

      return spendTime[W];
}

int main()
{
      int T;
      cin >> T;

      while (T--)
      {
            int N, K;
            cin >> N >> K;
            cout << TopologicalSort(N, K) <<"\n";
      }
}