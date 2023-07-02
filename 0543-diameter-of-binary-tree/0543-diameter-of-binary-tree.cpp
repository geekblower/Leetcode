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
    pair<int, int> Diameter(TreeNode* root) {
        if(root == NULL) {
            return {0, 0};
        }
        
        pair<int, int> D1 = Diameter(root->left);
        pair<int, int> D2 = Diameter(root->right);
        
        int opt1 = D1.first;
        int opt2 = D2.first;
        int opt3 = D1.second + D2.second + 1;
        
        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3));
        ans.second = max(D1.second, D2.second) + 1;
        
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return Diameter(root).first - 1;
    }
};