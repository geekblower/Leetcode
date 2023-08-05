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
    void solve(int &sum, TreeNode* root, int low, int high) {
        if(root == NULL) {
            return;
        }

        if(root->val >= low && root->val <= high) {
            sum += root->val;
        }

        solve(sum, root->left, low, high);
        solve(sum, root->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        solve(sum, root, low, high);
        return sum;
    }
};