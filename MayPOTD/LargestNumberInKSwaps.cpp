#include <string>
using namespace std;

class Solution
{
public:
    string findMaximumNum(string &s, int k)
    {
        string maxs = s;
        dfs(s, k, 0, maxs);
        return maxs;
    }

private:
    void dfs(string &s, int k, int idx, string &maxs)
    {
        if (k == 0 || idx >= (int)s.size() - 1)
            return;
        char mx = s[idx];
        for (int i = idx + 1; i < (int)s.size(); ++i)
            if (s[i] > mx)
                mx = s[i];
        if (mx != s[idx])
        {
            for (int i = s.size() - 1; i > idx; --i)
            {
                if (s[i] == mx)
                {
                    swap(s[idx], s[i]);
                    if (s > maxs)
                        maxs = s;
                    dfs(s, k - 1, idx + 1, maxs);
                    swap(s[idx], s[i]);
                }
            }
        }
        else
        {
            dfs(s, k, idx + 1, maxs);
        }
    }
};
