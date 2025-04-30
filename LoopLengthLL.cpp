struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head)
    {
        // Code here
        bool cycleFound = false;

        Node *fast = head;
        Node *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                cycleFound = true;
                break;
            }
        }

        if (cycleFound)
        {
            int length = 0;
            do
            {
                fast = fast->next;
                ++length;
            } while (fast != slow);
            return length;
        }
        else
        {
            return 0;
        }
    }
};
