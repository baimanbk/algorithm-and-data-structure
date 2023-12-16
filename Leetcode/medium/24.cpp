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
    ListNode* swapPairs(ListNode* head) {
                if(!head || !(head->next)){
            return head;
        }
        ListNode* ptr1=head;
        ListNode* ptr2=ptr1->next;

        ptr1->next=ptr2->next;
        ptr2->next=ptr1;

        ptr1->next=swapPairs(ptr1->next);

        return ptr2;
    }
};