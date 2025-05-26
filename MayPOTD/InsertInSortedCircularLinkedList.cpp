

class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = nullptr;
  }
}; 

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        
        Node* newNode = new Node(data);

        if(head->data >= data) {

            Node* current = head;

            while(current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            head = newNode;
            return head;

        }

        Node* current = head;
        while(current->next != head && current->next->data <= data) {
            current = current->next;
        }

        if(current->next == head) {
            current->next = newNode;
            newNode->next = head;
            return head;
        }

        newNode->next = current->next;
        current->next = newNode;
        return head;

    }
};