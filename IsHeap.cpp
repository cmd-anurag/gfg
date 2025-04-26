#include <queue>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool isHeap(Node *tree)
    {
        // code here
        std::queue<Node *> q;
        q.push(tree);

        bool nullFound = false;

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            if (current->left)
            {
                if (nullFound || current->data < current->left->data)
                    return false;
                q.push(current->left);
            }
            else
            {
                nullFound = true;
            }

            if (current->right)
            {
                if (nullFound || current->data < current->right->data)
                    return false;
                q.push(current->right);
            }
            else
            {
                nullFound = true;
            }
        }

        return true;
    }
};