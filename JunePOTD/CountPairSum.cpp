#include<vector>
using std::vector;

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        vector<int> flat1, flat2;
        for (int i = 0; i < n; ++i) {
            flat1.insert(flat1.end(), mat1[i].begin(), mat1[i].end());
            flat2.insert(flat2.end(), mat2[i].begin(), mat2[i].end());
        }
        int count = 0;
        int i = 0, j = flat2.size() - 1;
        while (i < flat1.size() && j >= 0) {
            int sum = flat1[i] + flat2[j];
            if (sum == x) {
                ++count;
                ++i;
                --j;
            } else if (sum < x) {
                ++i;
            } else {
                --j;
            }
        }
        return count;
    }
};
