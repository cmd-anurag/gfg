#include<string>
#include<vector>
#include<algorithm>

using std::string;

class Solution {
  public:
    int minDeletions(string s) {
        // code here
        int n = s.size();

        string t = s;
        std::reverse(t.begin(), t.end());
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1));

        for(int i = 1; i <= n; ++i) {

            for(int j = 1; j <= n; ++j) {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
            
        }

        return n - dp[n][n];
    }
};