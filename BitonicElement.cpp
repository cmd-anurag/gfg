#include<vector>
#include<climits>
using std::vector, std::max;

class Solution {
    public:
      int findMaximum(vector<int> &arr) {
          // code here
          // wait what
          int bitonicPoint = INT_MIN;
          for(int x : arr) {
              bitonicPoint = max(x, bitonicPoint);
          }
          return bitonicPoint;
      }
  };