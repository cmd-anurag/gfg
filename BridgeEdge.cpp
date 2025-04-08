#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
      bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
          // Code here
          unordered_map<int, vector<int>> adj;
          
          for(auto edgePair : edges) {
              if(edgePair[0] == c && edgePair[1] == d) continue;
              if(edgePair[1] == c && edgePair[0] == d) continue;
              
              adj[edgePair[0]].push_back(edgePair[1]);
              adj[edgePair[1]].push_back(edgePair[0]);
          }
          
          vector<bool> visited(V, false);
          
          // int visitedNodes = 0;
          stack<int> st;
          st.push(c);
          visited[c] = true;
          
          while(!st.empty()) {
              int top = st.top();
              st.pop();
              for(auto neighbor : adj[top]) 
              {
                  if(!visited[neighbor]) {
                      visited[neighbor] = true;
                      st.push(neighbor);
                  }
              }
          }
          
          
          return !visited[d];
      }
  };