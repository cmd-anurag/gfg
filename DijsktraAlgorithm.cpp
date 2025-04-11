#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          // Code here
          unordered_map<int, vector<pair<int, int>>> adj;
          
          for(auto edge : edges)
          {
              int u = edge[0];
              int v = edge[1];
              int w = edge[2];
              
              adj[u].push_back(make_pair(v, w));
              adj[v].push_back(make_pair(u, w));
          }
          
          unordered_map<int, int> dist;
          
          for(int i = 0; i < V; ++i) {
              if(i == src) {
                  dist[i] = 0;
                  continue;
              }
              dist[i] = INT_MAX;
          }
          
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
          minHeap.push(make_pair(0, src));
          
          while(!minHeap.empty()) {
              pair<int, int> top = minHeap.top();
              minHeap.pop();
              
              int node = top.second;
              
              for(auto edge : adj[node]) {
                  int neighbor = edge.first;
                  int weight = edge.second;
                  
                  if(dist[node] + weight < dist[neighbor]) {
                      dist[neighbor] = dist[node] + weight;
                      minHeap.push(make_pair(dist[neighbor], neighbor));
                  }
              }
          }
          
          vector<int> result(V);
          for(int i = 0; i < V; ++i) {
              result[i] = dist[i];
          }
          return result;
          
          
      }
  };