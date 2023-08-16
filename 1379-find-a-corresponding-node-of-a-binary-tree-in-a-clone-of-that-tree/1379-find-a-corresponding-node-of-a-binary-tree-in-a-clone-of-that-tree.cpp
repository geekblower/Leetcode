/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* searchNode(TreeNode* root1, TreeNode* root2, int data) {
        if(root1 == NULL) {
            return NULL;
        }

        if(root1->val == data) {
            return root2;
        }

        TreeNode* node1 = searchNode(root1->left, root2->left, data);
        TreeNode* node2 = searchNode(root1->right, root2->right, data);

        return (node1) ? node1 : node2;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return searchNode(original, cloned, target->val);
    }
};