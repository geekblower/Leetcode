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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(root == NULL)
            return answer;
        
        TreeNode *stack[100], *temp;
        int top = -1;
        temp = root;
        stack[++top] = root;
        
        while(top >= 0) {
            temp = stack[top--];
            
            if(temp != NULL)
                answer.push_back (temp->val);
            
            if(temp->right != NULL)
                stack[++top] = temp->right;
            
            if(temp->left != NULL)
                stack[++top] = temp->left;

        }
        
        return answer;
    }
};