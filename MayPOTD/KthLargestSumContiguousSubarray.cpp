#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int kthLargest(vector<int> &arr, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int n = arr.size();
        for (int i = 0; i < n; ++i)
        {
            long long sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += arr[j];
                pq.push(sum);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};