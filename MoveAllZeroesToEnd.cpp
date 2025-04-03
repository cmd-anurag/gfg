#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
      void pushZerosToEnd(vector<int>& arr) {
          int n = arr.size();
          int j = 0;
          for(int i = 0; i < n; ++i) {

            // i and j both move forward if its a non zero element;
            
            if(arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }

            // if a zero element is there only i moves forward and next time i is on a non zero element it is swapped with j which is still on the zero element;
          }
      }
        // Time Complexity - O(n)
        // Space Complexity - O(1)
      private:
        void swap(int &a, int &b) {
            int t = a;
            a = b;
            b = t;
        }
  };
 

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    
    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    solution.pushZerosToEnd(arr);

    cout << "Array after pushing zeros to the end: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

