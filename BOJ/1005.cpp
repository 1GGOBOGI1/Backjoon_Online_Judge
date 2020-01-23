#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
      int T;
      cin >> T;

      while(T--)
      {
            int N, K;
            cin >> N >> K;
      
            vector<vector<int> > graph(N+1);
            int indegree[N + 1];
            memset(indegree, 0, sizeof(indegree));

            for (int i = 1; i <= N;i++)
                  cin >> indegree[i];

            int X, Y;
            for (int i = 0; i < K; i++)
            {
                  cin >> X >> Y;
                  indegree[Y]++;
                  graph[X].push_back(Y);
            }

            
      }
}