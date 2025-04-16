#include<vector>
using namespace std;

class Solution {
    public:
    const int INF = 1e8;
    
      void floydWarshall(vector<vector<int>> &dist) {
          // Code here
          int n = dist.size();
          
          for(int k = 0; k < n; ++k)
          for(int i = 0; i < n; ++i)
          for(int j = 0; j < n; ++j) {
              if(dist[i][k] < INF && dist[k][j] < INF)
              {
                  dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
              }
          }
      }
  };