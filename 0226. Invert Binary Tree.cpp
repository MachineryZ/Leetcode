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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        if (root->left != NULL or root->right != NULL) {
            TreeNode* left_val = root->left;
            TreeNode* right_val = root->right;
            root->left = right_val;
            root->right = left_val;
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
        }
        return root;
    }
};