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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) {
            if (!list1)
                return list2;
            else if (!list2)
                return list1;
            else
                return {};
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* prev = nullptr;
        ListNode* next = list2->next;
        while (temp2) {

            ListNode* next = temp2->next;

            if (temp2->val < list1->val) {
                temp2->next = list1;
                list1 = temp2;
                temp1 = list1;
            } else {

                temp1 = list1;

                while (temp1->next && temp1->next->val < temp2->val) {
                    temp1 = temp1->next;
                }

                temp2->next = temp1->next;
                temp1->next = temp2;
            }

            temp2 = next;
        }
        if (temp2)
            prev->next = temp2;

        return list1;
    }
};