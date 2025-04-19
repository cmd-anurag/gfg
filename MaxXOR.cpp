#include <vector>
using std::vector, std::max;

class TrieNode
{
public:
    TrieNode *children[2];
    TrieNode()
    {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
            {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int findMaxXor(int num)
    {
        TrieNode *node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            if (node->children[oppositeBit])
            {
                maxXor = (maxXor << 1) | 1;
                node = node->children[oppositeBit];
            }
            else
            {
                maxXor = (maxXor << 1) | 0;
                node = node->children[bit];
            }
        }
        return maxXor;
    }
};

class Solution
{
public:
    int maxXor(vector<int> &arr)
    {
        Trie trie;
        int maxResult = 0;
        for (int num : arr)
        {
            trie.insert(num);
        }
        for (int num : arr)
        {
            int currentXor = trie.findMaxXor(num);
            maxResult = max(maxResult, currentXor);
        }
        return maxResult;
    }
};