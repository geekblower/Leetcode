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
    bool compareNodes(TreeNode* l, TreeNode* r) {
        // leaf node
        if(l == NULL && r == NULL) return true;
        
        // single child
        if(l == NULL || r == NULL) return false;
        
        // unequal values
        if(l->val != r->val) return false;
        
        return compareNodes(l->left, r->right) && compareNodes(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return compareNodes(root->left, root->right);
    }
};