#include <unordered_set>
#include <vector>

using std::unordered_set, std::vector;

class Solution
{
public:
    bool ValidCorner(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        unordered_set<long long> seen;
        for (int i = 0; i < n; ++i)
        {
            vector<int> cols;
            for (int j = 0; j < m; ++j)
                if (mat[i][j] == 1)
                    cols.push_back(j);
            for (int a = 0; a < cols.size(); ++a)
            {
                for (int b = a + 1; b < cols.size(); ++b)
                {
                    long long key = (long long)cols[a] * m + cols[b];
                    if (seen.count(key))
                        return true;
                    seen.insert(key);
                }
            }
        }
        return false;
    }
};
