#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int INF = numeric_limits<int>::max();

    int dijkstra(int V, int src, int dest, unordered_map<int, vector<pair<int, int>>> &graph)
    {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();
            int d = top.first;
            int u = top.second;
            if (u == dest)
                return d;
            if (d > dist[u])
                continue;
            vector<pair<int, int>> &neighbors = graph[u];
            for (size_t i = 0; i < neighbors.size(); ++i)
            {
                int v = neighbors[i].first;
                int w = neighbors[i].second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return INF;
    }

    int findMinCycle(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (size_t i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        int minCycle = INF;

        for (size_t i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];

            vector<pair<int, int>> &adjU = graph[u];
            vector<pair<int, int>> &adjV = graph[v];
            adjU.erase(remove_if(adjU.begin(), adjU.end(),
                                 [v, w](const pair<int, int> &p)
                                 { return p.first == v && p.second == w; }),
                       adjU.end());
            adjV.erase(remove_if(adjV.begin(), adjV.end(),
                                 [u, w](const pair<int, int> &p)
                                 { return p.first == u && p.second == w; }),
                       adjV.end());

            int pathWeight = dijkstra(V, u, v, graph);
            if (pathWeight != INF)
            {
                minCycle = min(minCycle, pathWeight + w);
            }

            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        return (minCycle == INF ? -1 : minCycle);
    }
};
// damn