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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
		
        if(height(root) == -1)
            return false;
		
        return true;
	}

    int height(TreeNode* root) {
		if(root == NULL)
            return 0;
		
        int Left = height(root->left);
		int Right = height(root->right);
		
        if(Left == -1 || Right == -1 || abs(Left - Right) > 1)
            return -1;
		
        return max(Left, Right) + 1;
    }
};