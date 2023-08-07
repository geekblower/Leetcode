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
    string getString(int x) {
        string ans = "";

        for(int i=x; i!=0; i/=10) {
            if(i<0) i*=-1;
            ans += (char)(i%10 + '0');
        }

        if(x < 0) ans += '-';
        reverse(ans.begin(), ans.end());

        return (x==0) ? "0" : ans;
    }

    void solve(TreeNode* root, string temp, vector<string> &solution) {
        if(root == NULL) {
            return;
        }

        if(root->left == NULL && root->right == NULL) {
            temp += getString(root->val);
            solution.push_back(temp);
            return;
        }

        if(root->left) {
            // cout << "Val = " << root->val << " ->";
            solve(root->left, (temp + getString(root->val) + "->"), solution);
        }

        if(root->right) {
            // cout << "Val = " << root->val << " ->";
            solve(root->right, (temp + getString(root->val) + "->"), solution);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> solution;
        string  temp;
        
        solve(root, temp, solution);
        
        return solution;
    }
};