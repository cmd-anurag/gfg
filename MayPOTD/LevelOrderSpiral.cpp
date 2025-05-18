#include<vector>
#include<stack>
using std::vector;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        vector<int> result;

        std::stack<Node *> s1; // left to right;
        std::stack<Node *> s2; // right to left;

        s1.push(root);

        while(!s1.empty() || !s2.empty()) {

            while(!s2.empty()) {
                Node* top = s2.top();
                s2.pop();
                result.push_back(top->data);
                if(top->left) {
                    s1.push(top->left);
                } 
                if(top->right) {
                    s1.push(top->right);
                }
            }

            while(!s1.empty()) {
                Node* top = s1.top();
                s1.pop();
                result.push_back(top->data);

                if(top->right) {
                    s2.push(top->right);
                }

                if(top->left) {
                    s2.push(top->left);
                }
            }

        }

        return result;
    }
};