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

    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        

    }

  };