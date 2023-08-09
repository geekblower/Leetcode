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
    void solve(TreeNode* &root, vector<int>& nums, int start, int end) {
        if(start > end) {
            return;
        }

        int mid = start + (end-start)/2;
        root = new TreeNode(nums[mid]);

        solve(root->left, nums, start, mid-1);
        solve(root->right, nums, mid+1, end);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        solve(root, nums, 0, nums.size()-1);
        return root;
    }
};