#include <bits/stdc++.h>

using namespace std;


//  i'll use it for cycle detection in kruskal's algorithm
class DisjointSetUnion
{
private:
    vector<int> parent;

public:
    DisjointSetUnion(int V)
    {
        parent.resize(V);
        for (int i = 0; i < V; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {

        while (parent[node] != node)
        {
            node = parent[node];
        }

        return node;
    }

    void doUnion(int x, int y)
    {
        int parent1 = find(x);
        int parent2 = find(y);

        if (parent1 != parent2)
        {
            parent[parent1] = parent2;
        }
    }
};

class Solution
{
public:
    int minCost(vector<vector<int>> &houses)
    {
        // code here
        int n = houses.size();

        vector<vector<int>> matrix(n, vector<int>(n));

        // building the adj matrix for the weight representation
        for (int i = 0; i < n; ++i)
        {
            int xi = houses[i][0];
            int yi = houses[i][1];

            for (int j = i + 1; j < n; ++j)
            {

                int xj = houses[j][0];
                int yj = houses[j][1];

                int manhattanDistance = abs(xi - xj) + abs(yi - yj);
                matrix[i][j] = manhattanDistance;
                matrix[j][i] = manhattanDistance;
            }
        }
        
        // a heap of triplets (weight, u, v) for kruskal
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap; // okay this is long

        // load the edges
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                minHeap.push({matrix[i][j], i, j});
            }
        }

        // union find to track if a cycle is created
        DisjointSetUnion dsu(n);

        int processedEdges = 0;
        int totalCost = 0;
        while(processedEdges < n-1) {

            // gfg doesnt support stuctured bindings oof
            tuple<int, int, int> edge = minHeap.top();
            minHeap.pop();

            int weight = get<0>(edge);
            int u = get<1>(edge);
            int v = get<2>(edge);

            if(dsu.find(u) != dsu.find(v)) {
                totalCost += weight;
                dsu.doUnion(u,v);
                ++processedEdges;    
            }
        }


        return totalCost;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> houses = {{0,0}, {1,1}, {1, 3}, {3, 0}};

    cout << sol.minCost(houses);
}