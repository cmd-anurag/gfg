#include<utility>
#include <algorithm>
// Node Structure


struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
    public:
      // Function to return the maximum sum of non-adjacent nodes.
      int getMaxSum(Node *root) {
          // code here
          std::pair<int, int> answer = solve(root);

          return std::max(answer.first, answer.second);
      }

    private:

    // this returns a pair having sums of if we include that node and if we exclude that node
    std::pair<int, int> solve(Node* root) {

        if(!root) return {0,0};

        // left child
        std::pair<int, int> left = solve(root->left);
        // right child
        std::pair<int, int> right = solve(root->right);

        // for the current node
        int include = root->data + left.second + right.second;
        int exclude = std::max(left.first, left.second) + std::max(right.first, right.second);

        return {include, exclude};

    }
      
  };

 