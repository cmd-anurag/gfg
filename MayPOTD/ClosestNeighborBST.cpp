
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int findMaxFork(Node *root, int k)
    {
        int ans = -1;
        Node *cur = root;
        while (cur)
        {
            if (cur->data <= k)
            {
                ans = cur->data;
                cur = cur->right;
            }
            else
            {
                cur = cur->left;
            }
        }
        return ans;
    }
};
