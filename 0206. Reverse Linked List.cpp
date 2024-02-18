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
        if (head == NULL)
            return head;
        vector<int> v;
        ListNode* p = head;
        while (p != NULL) {
            v.push_back(p->val);
            p = p->next;
        }
        p = head;
        for (int i = 0; i < v.size(); i++) {
            p->val = v[v.size() - 1 - i];
            p = p->next;
        }
        return head;
    }
};

// Recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
    }

};