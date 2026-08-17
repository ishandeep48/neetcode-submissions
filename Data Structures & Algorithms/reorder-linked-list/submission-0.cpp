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
    ListNode* findMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;
        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next) {
                next = next->next;
            }
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode*middle=findMiddle(head);
        ListNode*secondList = middle->next;
        middle->next=NULL;
        secondList = reverseList(secondList);
        ListNode* temp = head;
        ListNode* tempNext=head->next;
        while(secondList){
            ListNode*tempRev=secondList->next;
            secondList->next=tempNext;
            temp->next = secondList;
            temp=tempNext;
            if(temp) tempNext=temp->next;
            secondList=tempRev;
        }
    }
};