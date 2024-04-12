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
    stack<ListNode*> s;
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* node = head;
        while (node != nullptr) {
            while (s.size() > 0 and s.top()->val < node->val) {
                s.pop();
            }
            if (s.size() == 0) {
                head = node;
                s.push(node);
            }
            else if (s.size() > 0) {
                s.top()->next = node;
                s.push(node);
            }
            node = node->next;
        }
        return head;
    }
};