#include <vector>
using std::vector;

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        if (arr.empty())
            return -1;

        // code here
        int candidate = arr[0];
        int count = 0;

        for (int x : arr)
        {
            if (count == 0)
            {
                candidate = x;
            }

            if (x == candidate)
                ++count;
            else
            {
                --count;
            }
        }

        count = 0;
        for (int x : arr)
        {
            if (x == candidate)
            {
                ++count;
            }
        }

        int n = arr.size();
        if (count * 2 > n)
        {
            return candidate;
        }
        else
        {
            return -1;
        }
    }
};