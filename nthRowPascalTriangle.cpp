#include <vector>
#include <iostream>

using std::vector;

class Solution
{
public:
    vector<int> nthRowOfPascalTriangle(int n)
    {
        // code here
        vector<int> result(n);
        result[0] = 1;

        for (int i = 1; i < n; ++i)
        {
            result[i] = result[i - 1] * (n - i) / i;
        }

        return result;
    }
};

int main()
{
    Solution s;
    s.nthRowOfPascalTriangle(4);
}