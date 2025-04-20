#include <vector>
using std::vector;

class Solution
{
public:
    int findDuplicate(vector<int> &arr)
    {
        int n = arr.size();

        int actualXOR = 0;
        for (int x : arr)
        {
            actualXOR ^= x;
        }
        int expectedXOR = 0;
        for (int i = 1; i <= n - 1; ++i)
        {
            expectedXOR ^= i;
        }
        return expectedXOR ^ actualXOR;
    }
};