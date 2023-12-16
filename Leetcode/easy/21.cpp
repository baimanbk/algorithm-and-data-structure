class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(); // Create a dummy head node
        ListNode* current = dummyHead; // Pointer to the current node in the merged list
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        
        return dummyHead->next; // Skip the dummy head and return the merged list.
    }
};