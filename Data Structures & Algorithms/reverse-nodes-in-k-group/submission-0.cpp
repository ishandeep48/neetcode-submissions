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
    pair<ListNode*,ListNode*> reverseList(ListNode*slow,ListNode*fast){
        // ListNode*start=slow;
        ListNode*prev=nullptr;
        ListNode*curr=slow;
        ListNode*fastNext=fast->next;
        while(curr && curr!=fastNext){
            ListNode*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return {slow,prev};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*ans=head;
        bool isFist=true;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*slowPrev=nullptr;
        ListNode*fastNext=nullptr;
        while(fast){
            for(int i=1;i<k;i++){
                fast=fast->next;
                if(!fast) break;
            }
            if(!fast) break;
            fastNext = fast->next;
            
            pair<ListNode*,ListNode*> ph = reverseList(slow,fast);
            if(slowPrev) slowPrev->next=ph.second;
            else ans = ph.second;
            ph.first->next=fastNext;
            slowPrev=ph.first;
            slow=fastNext;
            fast=slow;
        }
        return ans;
    }
};