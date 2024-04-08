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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isEqualTree(root, subRoot))
            return true;
        if (root == nullptr or subRoot == nullptr)
            return false;
        else if (isEqualTree(root->right, subRoot) or isEqualTree(root->left, subRoot))
            return true;
        return false;
    }
    bool isEqualTree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr and subRoot == nullptr)
            return true;
        if (root != nullptr and subRoot == nullptr)
            return false;
        if (root == nullptr and subRoot != nullptr)
            return false;
        if (root->val != subRoot->val)
            return false;
        return isEqualTree(root->left, subRoot->left) and 
            isEqualTree(root->right, subRoot->right);
    }
};