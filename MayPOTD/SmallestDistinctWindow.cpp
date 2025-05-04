#include <unordered_map>
#include <climits>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int findSubString(string &str)
    {
        // code here
        unordered_map<char, int> map;
        unordered_set<char> uniqueCharacters(str.begin(), str.end());

        int required = uniqueCharacters.size();

        int left = 0;
        int right = 0;
        int formed = 0;

        int result = INT_MAX;

        while (right < str.length())
        {
            char ch = str[right];
            map[ch]++;

            if (map[ch] == 1)
            {
                formed++;
            }

            while (formed == required)
            {
                result = min(result, right - left + 1);

                char leftch = str[left];
                map[leftch]--;
                if (map[leftch] == 0)
                {
                    --formed;
                }
                ++left;
            }

            ++right;
        }
        return result;
    }
};