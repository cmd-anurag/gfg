#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(char node, unordered_map<char, vector<char>> &graph, unordered_map<char, int> &visited, string &res)
    {
        if (visited[node] == 1)
            return false;
        if (visited[node] == 2)
            return true;

        visited[node] = 1;

        if (graph.count(node)) {
            for (char neighbor : graph[node])
            {
                if (!dfs(neighbor, graph, visited, res))
                    return false;
            }
        }

        visited[node] = 2;
        res += node;
        return true;
    }

public:
    string findOrder(vector<string> &words)
    {
        int n = words.size();
        unordered_set<char> chars;
        for (const string& word : words)
        {
            for (char letter : word)
            {
                chars.insert(letter);
            }
        }

        unordered_map<char, vector<char>> graph;
        for(char c : chars) {
            graph[c] = {};
        }

        for (int i = 0; i < n - 1; ++i)
        {
            string word1 = words[i];
            string word2 = words[i + 1];
            int len1 = word1.size();
            int len2 = word2.size();
            int minLen = min(len1, len2);
            bool foundDifference = false;

            for (int j = 0; j < minLen; ++j)
            {
                char u = word1[j];
                char v = word2[j];
                if (u != v)
                {
                    bool edgeExists = false;
                    if (graph.count(u)) {
                        for(char neighbor : graph[u]) {
                            if (neighbor == v) {
                                edgeExists = true;
                                break;
                            }
                        }
                    }
                    if (!edgeExists) {
                         graph[u].push_back(v);
                    }
                    foundDifference = true;
                    break;
                }
            }

            if (!foundDifference && len1 > len2)
            {
                return "";
            }
        }

        string res;
        unordered_map<char, int> visited;
        for (char c : chars)
        {
            visited[c] = 0;
        }

        vector<char> charList(chars.begin(), chars.end());
        sort(charList.begin(), charList.end());

        for (char c : charList)
        {
            if (visited[c] == 0)
            {
                if (!dfs(c, graph, visited, res))
                {
                    return "";
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// this was tough..