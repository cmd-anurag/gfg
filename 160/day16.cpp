class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int arr[26] = {0};
        
        for(char c : s1)
        {
            arr[c - 'a']--;
        }
        for(char c : s2)
        {
            arr[c - 'a']++;
        }
        
        for(int i = 0; i < 26; ++i) {
            if(arr[i]) return false;
        }
        return true;
    }
};