#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        vector<int> arr(26, -1);
        int n = s.size();
        
        // -1 if the element is never seen
        // index i if element is seen only once
        // -2 if its repeating
        
        for(int i = 0; i < n; ++i)
        {
            char c = s[i];
            
            if(arr[c - 'a'] == -1)
            {
                arr[c - 'a'] = i;   
            }
            else if(arr[c - 'a'] >= 0)
            {
                arr[c - 'a'] = -2;
            }
        }
        char answer = '$';
        int minIndex = n;
        
        for(int i = 0; i < 26; ++i)
        {
            if(arr[i] >= 0 && arr[i] < minIndex)
            {
                minIndex = arr[i];
                answer = (char)(i + 'a');
            }
        }
        
        return answer;
    }
};