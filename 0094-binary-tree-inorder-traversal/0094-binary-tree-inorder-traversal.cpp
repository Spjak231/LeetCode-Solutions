class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vcc) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, vcc);   // Left
        vcc.push_back(root->val);   // Root
        inorder(root->right, vcc);  // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vcc;
        inorder(root, vcc);
        return vcc;
    }
};