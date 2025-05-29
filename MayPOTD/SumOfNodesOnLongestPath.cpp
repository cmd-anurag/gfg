
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int sumOfLongRootToLeafPath(Node *root) {
        int maxLen = 0, maxSum = 0;
        dfs(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
private:
    void dfs(Node *node, int len, int sum, int &maxLen, int &maxSum) {
        if (!node) return;
        len++;
        sum += node->data;
        if (!node->left && !node->right) {
            if (len > maxLen || (len == maxLen && sum > maxSum)) {
                maxLen = len;
                maxSum = sum;
            }
            return;
        }
        dfs(node->left, len, sum, maxLen, maxSum);
        dfs(node->right, len, sum, maxLen, maxSum);
    }
};
