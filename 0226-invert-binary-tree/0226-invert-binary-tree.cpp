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
    void solve(TreeNode* &root) {
        if(root == NULL) {
            return;
        }
        
        solve(root->left);
        solve(root->right);
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};