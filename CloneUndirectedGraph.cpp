#include<vector>
#include<unordered_map>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    public:
      unordered_map<Node*, Node*> cloned;
  
      Node* cloneGraph(Node* node) {
          if (!node) return nullptr;
          if (cloned.find(node) != cloned.end()) return cloned[node];
  
          Node* clone = new Node(node->val);
          cloned[node] = clone;
  
          for (auto neighbor : node->neighbors) {
              clone->neighbors.push_back(cloneGraph(neighbor));
          }
  
          return clone;
      }
  };