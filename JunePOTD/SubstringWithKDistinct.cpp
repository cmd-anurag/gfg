
#include<unordered_map>
#include <string>
using std::unordered_map;
using std::string;

class Solution {
  public:
    int countAtMostK(string& s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;
        int left = 0, right = 0;
        int count = 0;
        
        for (right = 0; right < n; ++right) {
            freq[s[right]]++;
            
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
            
            count += (right - left + 1); 
        }
        return count;
    }

    int countSubstr(string& s, int k) {
        if (k == 0) return 0;
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};