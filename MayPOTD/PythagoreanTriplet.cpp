#include<vector>
#include<unordered_set>
using std::vector;

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        std::unordered_set<int> sq;

        for(int num : arr) {
            sq.insert(num * num);
        }

        for(int i = 0; i < arr.size(); ++i) {
            for(int j = i+1; j < arr.size(); ++j) {
                int sum = arr[i]*arr[i] + arr[j]*arr[j];
                if(sq.count(sum)) {
                    return true;
                }
            }
        }
        return false;
    }
    // lol this got accepted? i for sure was prepared for a TLE
};