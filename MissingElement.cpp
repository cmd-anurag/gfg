#include <vector>
using std::vector;

class Solution
{
public:
    int missingNum(vector<int> &arr)
    {
        // code here
        int e = 0;
        int a = 0;

        for (int i : arr)
        {
            a ^= i;
        }
        int n = arr.size();
        for (int i = 1; i <= n + 1; ++i)
        {
            e ^= i;
        }
        return a ^ e;
    }
};