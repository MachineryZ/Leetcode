struct cmp
{
    bool operator()(const ListNode* l1, const ListNode* l2)
    {
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for(int i = 0; i < k; i++)
            if(lists[i] != nullptr)
                heap.push(lists[i]);
        if(heap.empty() == true)
            return NULL;
        ListNode* result = heap.top();
        heap.pop();
        if(result->next != nullptr)
            heap.push(result->next);
        ListNode* tail = result;
        while(!heap.empty())
        {
            tail->next = heap.top();
            heap.pop();
            tail = tail->next;
            if(tail->next)
                heap.push(tail->next);
        }
        return result;
        
    }
};