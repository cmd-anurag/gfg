#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
      
    void dfs(int u, int parent, unordered_map<int, vector<int>> &adj,
    vector<int> &tin, vector<int> &low,
    vector<bool> &visited,
    vector<bool> &isArticulation,
    int &timer
    ) 
    {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;
        
        for(int v : adj[u]) {
            if(v == parent) continue;
            if(visited[v]) {
                low[u] = min(low[u], tin[v]);
            }
            else {
                dfs(v, u, adj, tin, low, visited, isArticulation, timer);
                low[u] = min(low[u], low[v]);
                
                if(low[v] >= tin[u] && parent != -1) {
                    isArticulation[u] = true;
                }
                ++children;
            }
        }
        if(parent == -1 && children > 1) {
            isArticulation[u] = true;
        }
        
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        
        unordered_map<int, vector<int>> adj;
        
        for(auto edgePair : edges) {
            int u = edgePair[0];
            int v = edgePair[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> tin(V, -1), low(V, -1);
        vector<bool> visited(V, false);
        vector<bool> isArticulation(V, false);
        int timer = 0;
        for(int i = 0; i < V; ++i) {
            if(!visited[i]) {
                dfs(i, -1, adj, tin, low, visited, isArticulation, timer);
            }
        }
        
        vector<int> result;
        for(int i = 0; i < V; ++i) {
            if(isArticulation[i]) result.push_back(i);
        }
        
        if(result.empty()) return {-1};
        return result;
    }
};