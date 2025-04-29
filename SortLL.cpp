#include<vector>
using std::vector;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *segregate(Node *head)
    {
        // code here
        vector<int> map(3, 0);

        Node *current = head;

        while (current)
        {
            map.at(current->data) += 1;
            current = current->next;
        }

        current = head;
        while (map.at(0) > 0)
        {
            current->data = 0;
            current = current->next;
            map.at(0)--;
        }
        while (map.at(1) > 0)
        {
            current->data = 1;
            current = current->next;
            map.at(1)--;
        }
        while (map.at(2) > 0)
        {
            current->data = 2;
            current = current->next;
            map.at(2)--;
        }

        return head;
    }
};