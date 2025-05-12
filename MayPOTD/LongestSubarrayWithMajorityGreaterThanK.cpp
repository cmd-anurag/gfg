
#include <vector>
using std::max;
using std::vector;

// User function Template for C++
class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (arr[i] > k ? 1 : -1);
        vector<int> st;
        for (int i = 0; i <= n; i++)
            if (st.empty() || pref[i] < pref[st.back()])
                st.push_back(i);
        int ans = 0;
        for (int j = n; j >= 0; j--)
            while (!st.empty() && pref[j] > pref[st.back()])
            {
                ans = max(ans, j - st.back());
                st.pop_back();
            }
        return ans;
    }
};
