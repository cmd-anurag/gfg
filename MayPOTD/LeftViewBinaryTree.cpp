#include <vector>
#include <queue>
using std::vector;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> leftView(Node *root)
    {
        // code here
        if(!root) {
            return {};
        }

        std::queue<Node *> q;
        q.push(root);

        vector<int> result;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                Node* front = q.front();
                q.pop();

                if(i == 0) {
                    result.push_back(front->data);
                }
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }
        }
        return result;
    }
};