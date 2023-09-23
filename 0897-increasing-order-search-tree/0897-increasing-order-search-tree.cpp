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
    void inorder(TreeNode* root, vector<int> &tree) {
        if(root == NULL) return;
        
        inorder(root->left, tree);
        tree.push_back(root->val);
        inorder(root->right, tree);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> tree;
        inorder(root, tree);
        
        TreeNode* ans = new TreeNode(tree[0]);
        TreeNode* temp = ans;
        
        for(int i=1; i<tree.size(); i++) {
            temp->right = new TreeNode(tree[i]);
            temp = temp->right;
        }
        
        return ans;
    }
};