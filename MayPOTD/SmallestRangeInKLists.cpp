#include <vector>
#include<climits>
#include<queue>
#include<iostream>

using std::vector, std::cout;

typedef std::pair<int, std::pair<int, int>> PAIR;

class Solution
{
public:
    vector<int> findSmallestRange(vector<vector<int>> &arr)
    {
        // code here
        std::priority_queue<PAIR, vector<PAIR>, std::greater<PAIR>> minHeap;

        int k = arr.size(); // rows
        int n = arr.at(0).size(); // columns

        vector<int> ans(2);

        int left = INT_MAX;
        int right = INT_MIN;
        int minRange = INT_MAX;

        for(int i = 0; i < k; ++i) {

            minHeap.push({arr[i][0], {i, 0}});
            right = std::max(right, arr[i][0]);

        }

        while(1) {

            auto pair = minHeap.top();
            minHeap.pop();

            left = pair.first;

            auto indices = pair.second;
            int i = indices.first;
            int j = indices.second;

            int currentRange = right - left;

            if(currentRange < minRange) {
                minRange = currentRange;
                ans[0] = left;
                ans[1] = right;
            }

            j++;
            if(j >= n) break;

            right = std::max(right, arr[i][j]);
            minHeap.push({arr[i][j], {i, j}});
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> arr = {{4, 7, 9, 12, 15}, {0, 8, 10, 14, 20}, {6, 12, 16, 30, 50}};
    vector<int> ans = s.findSmallestRange(arr);
    cout << ans.at(0) << " " << ans.at(1);
}