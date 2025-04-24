#include <vector>
using std::vector;

class Solution
{
public:
    int getSingle(vector<int> &arr)
    {
        // code here
        int ones = 0;
        int twos = 0;

        for (int x : arr)
        {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;
    }
};