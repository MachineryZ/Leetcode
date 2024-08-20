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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        std::queue<TreeNode*> q;
        if (root == NULL) {
            return ret;
        }
        q.push(root);
        while(q.size() > 0) {
            int size = q.size();
            int maxn = INT_MIN;
            while(size--) {
                TreeNode* node = q.front();
                maxn = std::max(maxn, node->val);
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            ret.push_back(maxn);
        }
        return ret;
    }
};