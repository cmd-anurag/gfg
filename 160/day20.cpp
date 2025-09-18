#include<vector>
#include<string>
using namespace std;

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        string text = s2 + s2;
        string pattern = s1;
        return KMP(text, pattern);
    }
  private:
    vector<int> createLPS(string& pattern) {
        int n = pattern.size();
        vector<int> lps(n);
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while(i < n) {
            if(pattern[len] != pattern[i] && len == 0) {
                lps[i] = 0;
                ++i;
            }
            else if(pattern[len] != pattern[i] && len > 0) {
                len = lps[len - 1];
            }
            else if(pattern[len] == pattern[i]) {
                ++len;
                lps[i] = len;
                ++i;
            }
        }
        return lps;
    }
    
    bool KMP(string &text, string &pattern) {
        int i = 0;
        int j = 0;
    
        vector<int> lps = createLPS(pattern);
    
        while(i < text.size())
        {
            if(text[i] == pattern[j]) {
                ++i;
                ++j;
            }
            else {
                if(j > 0) {
                    j = lps[j-1];
                } else {
                    ++i;
                }
            }
            if(j == pattern.size()) return true;
        }
        return false;
        
    }
    
};