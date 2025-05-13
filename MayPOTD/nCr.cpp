#include <vector>
using std::min;
using std::vector;

class Solution {
  public:
    int nCr(int n, int r)
    {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(r+1, 0));

        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= min(i, r); ++j) {
                if(j == 0 || j == i) dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }

        return dp[n][r];
    }
};