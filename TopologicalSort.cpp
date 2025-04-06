#include<bits/stdc++.h>
using namespace std;


class Solution {
    
    unordered_map<int, vector<int>> adj;    
    
    void dfs(int source, vector<bool> &visited, stack<int> &answer) {
        
        for(auto neighbor : adj[source]) {
            
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                dfs(neighbor, visited, answer);
            }
        }
        
        answer.push(source);
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        for(auto edgePair : edges) {
            adj[edgePair[0]].push_back(edgePair[1]);
        }
        
        vector<bool> visited(V, false);
        
        stack<int> answer;
        
        for(int i = 0; i < V; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                dfs(i, visited, answer);
            }
        }
        
        vector<int> result;
        while(!answer.empty())
        {
            result.push_back(answer.top());
            answer.pop();
        }
        
        // for(int i : result) {
        //     cout << i << " ";
        // }
        
        return result;
        
    }
};