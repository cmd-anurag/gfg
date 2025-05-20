#include <bits/stdc++.h>
using namespace std;

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
    int minTime(Node *root, int target)
    {
        if (!root)
            return 0;

        unordered_map<Node *, Node *> parent;
        Node *targetNode = nullptr;
        buildParentMap(root, nullptr, parent, target, targetNode);

        unordered_set<Node *> visited;
        queue<Node *> q;
        q.push(targetNode);
        visited.insert(targetNode);

        int time = 0;
        while (!q.empty())
        {
            int sz = q.size();
            bool spread = false;

            for (int i = 0; i < sz; ++i)
            {
                Node *cur = q.front();
                q.pop();

                if (cur->left && !visited.count(cur->left))
                {
                    visited.insert(cur->left);
                    q.push(cur->left);
                    spread = true;
                }

                if (cur->right && !visited.count(cur->right))
                {
                    visited.insert(cur->right);
                    q.push(cur->right);
                    spread = true;
                }

                Node *par = parent[cur];
                if (par && !visited.count(par))
                {
                    visited.insert(par);
                    q.push(par);
                    spread = true;
                }
            }

            if (spread)
                ++time;
        }

        return time;
    }

private:
    void buildParentMap(Node *node, Node *par,
                        unordered_map<Node *, Node *> &parent,
                        int target, Node *&targetNode)
    {
        if (!node)
            return;
        parent[node] = par;
        if (node->data == target)
        {
            targetNode = node;
        }
        buildParentMap(node->left, node, parent, target, targetNode);
        buildParentMap(node->right, node, parent, target, targetNode);
    }
};