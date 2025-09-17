#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> createLPS(string &pattern) {
    int n = pattern.size();
    vector<int> lps(n);
    int len = 0;

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

vector<int> KMP(string &text, string &pattern) {
    vector<int> result;
    vector<int> lps = createLPS(pattern);

    int i = 0;
    int j = 0;

    while(i < text.length()) 
    {
        if(text[i] == pattern[j]) 
        {
            ++i;
            ++j;
        }
        else 
        {
            if(j != 0)
            j = lps[j - 1];
            else ++i;
        }

        if(j == pattern.length())
        {
            result.push_back(i - j);
            j = lps[j - 1];
        }
    }

    return result;
}

int main() {
    string text = "aabaacaadaabaaba";
    string pattern = "aaba";

    vector<int> result = KMP(text, pattern);
    for(int i : result)
    {
        cout << i << " ";
    }
    return 0;
}