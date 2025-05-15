#include<string>
#include<vector>
using std::string, std::vector;

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        
        // int result = n;

        // for(int i = 0; i < n; ++i) {
        //     for(int j = i+1; j < n; ++j) {
        //         if(s.at(i) == s.at(j)) ++result;
        //     }
        // }
        // return result;

        // TLE :(

        vector<int> map(26, 0);
        for(char c : s) {
            map[c - 'a']++;
        }

        int result = 0;

        // if a character c appears at k indices, the number of valid substrings possible (start and last both = c) is kC2 + k

        for(int i = 0; i < 26; ++i) {
            int k = map[i];
            result += (k * (k-1)) / 2 + k;
        }

        return result;
    }
};