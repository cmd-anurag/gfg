#include<vector>
#include<string>
#include<iostream>
using namespace std;


vector<string> improvedExtractWords(string &s)
{
    string word;
    vector<string> words;

    for(char c : s)
    {
        if(c == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }

    words.push_back(word);
    cout << "WORDS EXTRACTED USING APPROACH 2\n";
    for(auto word : words) {
        cout << word << " ";
    }
    return words;
}