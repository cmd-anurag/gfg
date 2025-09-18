#include <iostream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;

class Solution {
  public:
    int minChar(string &s) {
        // code here
        
        int n = s.length();
        
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        
        string pattern = s + "$" + reversed;
        
        vector<int> lps = createLPS(pattern);
        return n - lps.back();
        
    }
  private:
    vector<int> createLPS(string &pattern) {

        int n = pattern.size();
        int len = 0;
        vector<int> lps(n);
    
        lps[0] = 0;
        int i = 1;
        while(i < n)
        {
            if(pattern[len] != pattern[i] && len == 0)
            {
                lps[i] = 0;
                ++i;
            }
            else if(pattern[len] != pattern[i] && len > 0)
            {
                len = lps[len - 1];
            }
            else if(pattern[len] == pattern[i])
            {
                ++len;
                lps[i] = len;
                ++i;
            }
        }
        return lps;
    }
};
