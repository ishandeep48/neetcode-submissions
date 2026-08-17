/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextptr= head->next;
        while(curr){
            curr->next=prev;
            // nextptr->next=curr;
            prev = curr;
            curr = nextptr;
            if (curr) nextptr= curr->next;
        }
        return prev;
    }
};