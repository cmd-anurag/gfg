#include<vector>
#include <climits>
using std::vector;

class Solution {
public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> result;
        int idx = 0;
        dfs(LLONG_MIN, LLONG_MAX, preorder, idx, result);
        return result;
    }

private:
    
    bool dfs(long low, long high,
             const vector<int>& pre, int& idx,
             vector<int>& result)
    {
        if (idx >= pre.size() || pre[idx] < low || pre[idx] > high)
            return false;

        int val = pre[idx++];
        bool hasL = dfs(low, val, pre, idx, result);
        bool hasR = dfs(val, high, pre, idx, result);
        if (!hasL && !hasR)
            result.push_back(val);
        return true;
    }
};