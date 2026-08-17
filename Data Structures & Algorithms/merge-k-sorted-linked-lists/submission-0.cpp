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

struct Compare{
    bool operator()(ListNode*a, ListNode*b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        for(auto&i:lists){
            if(i) pq.push(i);
        }
        ListNode*start=nullptr;
        ListNode*temp=nullptr;;
        while(pq.size()>1){
            ListNode* min=pq.top();
            pq.pop();
            if(!start){
                start=temp=min;
            }else{
                temp->next=min;
                temp=temp->next;
            }
            min=min->next;
            if(min){
                pq.push(min);
            }
        }
        if(pq.size()==1 ){
            if(!start) start=temp=pq.top();
            else if(temp)temp->next=pq.top();
        }
        return start;
    }
};