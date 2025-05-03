
class Node
{
public:
    int val;
    Node *next;
    Node(int num)
    {
        val = num;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *primeList(Node *head)
    {
        // code here

        Node *current = head;
        while (current)
        {
            current->val = findNearestPrime(current->val);
            current = current->next;
        }

        return head;
    }

private:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int findNearestPrime(int n)
    {
        if (isPrime(n))
            return n;

        int forward = n + 1;
        int backward = n - 1;

        while (true)
        {
            if (isPrime(backward))
            {
                return backward;
            }
            if (isPrime(forward))
            {
                return forward;
            }
            forward++;
            backward--;
        }
    }
};