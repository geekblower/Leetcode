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
    int maxIndex(vector<int> &nums, int start, int end) {
        int max = INT_MIN, ans = -1;
    
        for(int i=start; i<=end; i++) {
            if(nums[i] > max) {
                max = nums[i];
                ans = i;
            }
        }

        return ans;
    }

    void buildTree(TreeNode* &root, vector<int> &nums, int start, int end) {
        if(start > end) {
            return;
        }

        int index = maxIndex(nums, start, end);
        root = new TreeNode(nums[index]);

        buildTree(root->left, nums, start, index-1);
        buildTree(root->right, nums, index+1, end);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root;
        buildTree(root, nums, 0, nums.size()-1);
        return root;
    }
};