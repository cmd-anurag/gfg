#include<bits/stdc++.h>

using namespace std;

// the good old graph cycle detection problem. It can be solved traditionally by performing a traversal and checking if a node can be reached via two distinct parents.

// a better way is using the disjoint set data structure (specifically the union and find operations)
// since STL doesnt provide it i'll implement my own.

class DisjointSetUnion {
    private:
        vector<int> parent;

    public:
        DisjointSetUnion(int V) {

            parent.resize(V);

            for(int i = 0; i < V; ++i) {
                parent[i] = i;
            }
        }

        
        int find(int x) {
            while(x != parent[x]) {
                x = parent[x];
            }
            return x;
        } 
        

        int doUnion(int a, int b) {
            int parent1 = find(a);
            int parent2 = find(b);

            if(parent1 != parent2) {
                parent[parent1] = parent2;
            }
        }
};
// nice


class Solution {
   
    public:
      bool isCycle(int V, vector<vector<int>>& edges) {
          // Code here
          DisjointSetUnion set = DisjointSetUnion(V);
          for(auto edgePair: edges) {

            int parent1 = set.find(edgePair[0]);
            int parent2 = set.find(edgePair[1]);


            if(parent1 == parent2) {
                return true;
            }
            else {
                set.doUnion(parent1, parent2);
            }
          }
          return false;
      }

      // this solution is elegant indeed
  };