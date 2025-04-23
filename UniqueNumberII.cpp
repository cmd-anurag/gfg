#include<vector>
using std::vector;

class Solution {
    public:
      vector<int> singleNum(vector<int>& arr) {
          // Code here.

          int total = 0;
          for(int x : arr) {
            total ^= x;
          }
          // calculate the total XOR sum of the array, this is essentially the XOR of two distinct elements;

          int rightmostBit = total & -total;  // the rightmost bit which differs between the two distinct integers;

          int firstNumber = 0; // xor sum of the elements which have the differing rightmost bit set;
          int secondNumber = 0; // xor sum of the elements which have the differing rightmost bit not set;

          for(int x : arr) {
            if(x & rightmostBit) { // check if the bit is set
                firstNumber ^= x;
            }
            else {
                secondNumber ^= x;
            }
          }


          vector<int> result(2);
          if(firstNumber < secondNumber){
            result[0] = firstNumber;
            result[1] = secondNumber;
          }
          else {
            result[0] = secondNumber;
            result[1] = firstNumber;
          }

          return result;

      }
  };
  