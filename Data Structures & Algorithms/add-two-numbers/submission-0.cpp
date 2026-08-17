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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=l1;ListNode*prev1=nullptr;
        ListNode*temp2=l2;ListNode*prev2=nullptr;
        int carry=0;
        while(temp1 || temp2 ||carry){
            if(temp1 && temp2){
                int ans = temp1->val+temp2->val+carry;
                carry = ans/10;
                temp1->val=ans%10;
                prev1=temp1;prev2=temp2;
                temp1=temp1->next;
                temp2=temp2->next;
            }else if(temp1){
                int ans =  temp1->val+carry;
                carry= ans/10;
                temp1->val=ans%10;
                prev1=temp1;
                temp1=temp1->next;
            }else if(temp2){
                int ans = temp2->val+carry;
                carry=ans/10;
                temp2->val = ans%10;
                prev1->next=temp2;
                prev1=temp2;
                temp2=temp2->next;
            }else if(carry){
                prev1->next= new ListNode(carry);
                carry=0;
            }
        }
        return l1;
    }
};