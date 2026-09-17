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
    void post(TreeNode* root, vector<int>& vcc) {
        if (root == NULL) {
            return;
        }
        post(root->left, vcc);    // Left
        post(root->right, vcc);   // Right
        vcc.push_back(root->val); // Root
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vcc;
        post(root, vcc);
        return vcc;
    }
};