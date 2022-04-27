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
    int max_depth;
    int maxDepth(TreeNode* root) 
    {
        max_depth = 0;
        int cur_depth = 0;
        dfs(root, cur_depth+1);
        return max_depth;
    }
    void dfs(TreeNode* node, int cur_depth)
    {
        if(node == nullptr)
            return;
        max_depth = max(max_depth, cur_depth);
        dfs(node->left, cur_depth+1);
        dfs(node->right, cur_depth+1);
        return;
    }
    
};