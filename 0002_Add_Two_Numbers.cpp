class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int add = 0;
        return helper(l1, l2, add);
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int add)
    {
        if(l1 == NULL && l2 == NULL && add == 0)
            return NULL;
        int val1 = (l1 == NULL) ? 0 : l1->val;
        int val2 = (l2 == NULL) ? 0 : l2->val;
        ListNode* next1 = (l1 == NULL) ? NULL : l1->next;
        ListNode* next2 = (l2 == NULL) ? NULL : l2->next;
        ListNode* node = new ListNode((val1 + val2 + add)%10);
        add = (val1 + val2 + add)/10;
        node->next = helper(next1, next2, add);
        return node;
    }
};