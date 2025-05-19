#include <vector>

using std::vector;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        // code here
        vector<Node *> result(2, nullptr);
        Node *curr = root;

        while (curr)
        {
            if (curr->data == key)
            {
               
                if (curr->left)
                    result[0] = findPre(curr->left);

                
                if (curr->right)
                    result[1] = findSuc(curr->right);
                break;
            }
            else if (curr->data > key)
            {
                // Current node could be successor
                result[1] = curr;
                curr = curr->left;
            }
            else
            {
                // Current node could be predecessor
                result[0] = curr;
                curr = curr->right;
            }
        }

        return result;
    }

private:
    Node *findPre(Node *root)
    {
        while (root->right)
        {
            root = root->right;
        }
        return root;
    }
    Node *findSuc(Node *root)
    {
        while (root->left)
        {
            root = root->left;
        }
        return root;
    }
};