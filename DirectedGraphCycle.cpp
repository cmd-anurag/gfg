#include<bits/stdc++.h>

using namespace std;

// kahn's algorithm

class Solution {
    public:
      bool isCyclic(int V, vector<vector<int>> &edges) {
          // code here
          unordered_map<int, vector<int>> adj;
          
          vector<int> indegree(V, 0);
          
          for(auto edgePair : edges) {
              adj[edgePair[0]].push_back(edgePair[1]);
              indegree[edgePair[1]]++;
          }
          
          // for(int i : indegree) {
          //     cout << i << " "; 
          // }
          
          queue<int> q;
          for(int i = 0; i < V; ++i) {
              if(indegree[i] == 0) {
                  q.push(i);
              }
          }
          
  
          
          int processed = 0;
          
          while(!q.empty())
          {
              int front = q.front();
              q.pop();
              ++processed;
              
              for(auto neighbor : adj[front]) {
                  if(indegree[neighbor] == 0) continue;
                  indegree[neighbor]--;
                  if(indegree[neighbor] == 0) {
                      q.push(neighbor);
                  }
              }
          }
          
          return processed < V;
          
      }
  };