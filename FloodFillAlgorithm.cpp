#include <bits/stdc++.h>
using namespace std;

// Flood Fill Algorithm
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, false));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        int pixel = image[sr][sc];
        visited[sr][sc] = true;
        q.push(make_pair(sr, sc));

        while (!q.empty())
        {
            pair<int, int> front = q.front();
            int x = front.first;
            int y = front.second;
            image[x][y] = newColor;
            q.pop();

            for (auto direction : directions)
            {
                int dx = direction.first;
                int dy = direction.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && image[nx][ny] == pixel)
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        return image;
    }
};