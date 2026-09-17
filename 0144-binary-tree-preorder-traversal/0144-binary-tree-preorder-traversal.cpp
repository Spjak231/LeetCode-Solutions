/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& vcc) {
        if (root == NULL) {
            return;
        }

        vcc.push_back(root->val);  // Root
        preorder(root->left, vcc);  // Left
        preorder(root->right, vcc); // Right
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vcc;
        preorder(root, vcc);
        return vcc;
    }
};