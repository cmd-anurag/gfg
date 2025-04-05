#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    
    void dfs(vector<vector<char>> &grid, int i , int j, vector<vector<bool>> &visited) {
        

        if(grid[i][j] == 'W') return;

        visited[i][j] = true;

        for(auto direction : directions) {

            int dx = direction.first;
            int dy = direction.second;

            int nx = i + dx;
            int ny = j + dy;

            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !visited[nx][ny]) {
                dfs(grid, nx, ny, visited);
            }
        }

    }

      int countIslands(vector<vector<char>>& grid) {
          // Code here
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int islandCount = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                // for each cell with L visit all possible L and mark them visited
                if(grid[i][j] == 'L' && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    ++islandCount;
                }
            }
        }

        return islandCount;
        
        
      }
  };