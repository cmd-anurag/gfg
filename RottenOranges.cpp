#include<bits/stdc++.h>

using namespace std;


class Solution {
    public:
      int UNOPTIMIZEDorangesRotting(vector<vector<int>>& mat) {
          
          int n = mat.size();
          int m = mat[0].size();
          
          // Code here
          int gen = 0;
          bool infected = false;
          
          vector<vector<int>> genMap(n, vector<int>(m, -1));
          
          
          
          while(true) {
              infected = false;
              
              for(int i = 0; i < n; ++i) {
                  
                  for(int j = 0; j < m; ++j) {
                      
                      if(mat[i][j] != 2) continue;
                      
                      if(genMap[i][j] == gen) continue;
                      // cout << "test ";
                      
                      // top
                      if(i > 0 && mat[i-1][j] == 1) {
                          mat[i-1][j] = 2;
                          infected = true;
                          genMap[i-1][j] = gen;
                      }
                      
                      // down
                      if(i < n-1 && mat[i+1][j] == 1) {
                          mat[i+1][j] = 2;
                          infected = true;
                          genMap[i+1][j] = gen;
                      }
                      
                      // left
                      if(j > 0 && mat[i][j-1] == 1) {
                          mat[i][j-1] = 2;
                          infected = true;
                          genMap[i][j-1] = gen;
                      }
                      
                      // right
                      if(j < m-1 && mat[i][j+1] == 1) {
                          mat[i][j+1] = 2;
                          infected = true;
                          genMap[i][j+1] = gen;
                      }
                          
                  }
                  
              }
              
              
              if(!infected) break;
              gen++;
          }
          
          int freshCount = 0;
          
          for(int i = 0; i < n; ++i) {
              for(int j = 0; j < m; ++j) {
                  if(mat[i][j] == 1) ++freshCount;
              }
          }
          
         if(freshCount) {
          //   cout << gen;
             return -1;
         } 
         else {
             return gen;
         }
      }
      // this wasn't accepted cause of the O(m*n*gen) time complexity, i guess i'll have to do better.

    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int freshOranges = 0;
        int minutes = 0;

        // adding all rotten oranges to queue and counting the fresh oranges
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1){
                    ++freshOranges;
                }
                else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        // if there aren't any fresh oranges , all oranges are already rotten hence output = 0;
        if(!freshOranges) return 0;

        // bfs time
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            int size = q.size();
            bool infected = false;

            // process the rotten oranges present in the queue
            for(int i = 0; i < size; ++i) {
                
                pair<int, int> front = q.front();
                int x = front.first;
                int y = front.second;
                q.pop();

                // infect the neighbors
                for(auto p : directions) {

                    int nx = x + p.first;
                    int ny = y + p.second;

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // infected
                        q.push({nx, ny}); // push to infected queue
                        freshOranges--;
                        infected = true;
                    }
                }
            }

            // if there has been an infection in the last iteration of queue.
            if(infected) ++minutes;
        }

        
        if(freshOranges == 0) {
            // every orange was successfully infected . you win
            return minutes;
        }
        else {
            // a fresh orange survived...
            return -1;
        }
    }

    // Time Complexity - O(n*m)
    // Space Complexity = O(n*m)

  };