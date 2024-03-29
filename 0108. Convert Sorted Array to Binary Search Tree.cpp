/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n = nums.size();
        return build(nums, 0, n-1);        
    }
    TreeNode* build(vector<int>& nums, int left, int right)
    {
        int len = right - left;
        if(len < 0)
            return nullptr;
        int mid = (left + right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->right = build(nums, mid+1, right);
        root->left = build(nums, left, mid-1);
        return root;
    }
};