#include <vector>
using std::vector;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    vector<vector<int>> Paths(Node *root)
    {
        // code here
        vector<vector<int>> result;
        vector<int> path;
        solve(root, result, path);

        return result;
    }

private:
    void solve(Node *root, vector<vector<int>> &result, vector<int> path)
    {
        if (!root)
        {
            return;
        }

        path.push_back(root->data);

        if (!root->left && !root->right)
        {
            result.push_back(path);
        }

        solve(root->left, result, path);
        solve(root->right, result, path);
    }
};