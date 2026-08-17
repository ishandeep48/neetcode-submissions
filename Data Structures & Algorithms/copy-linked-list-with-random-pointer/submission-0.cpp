/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* temp = head;
        while (temp) {
            Node* new_node = new Node(temp->val);
            new_node->next = temp->next;
            temp->next = new_node;
            temp = new_node->next;
        }
        temp = head;
        Node* prev = head;
        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node* copyHead = head->next;
        temp = head;

        while (temp) {
            Node* copy = temp->next;

            temp->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            temp = temp->next;
        }

        return copyHead;
    }
};