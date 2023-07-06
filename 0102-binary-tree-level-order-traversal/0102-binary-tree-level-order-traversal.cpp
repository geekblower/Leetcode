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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) {
            vector<vector<int>> v;
            return v;
        }

        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);

        vector<vector<int>> Answer;
        vector<int> temp;
        
        while(!Q.empty()) {
            TreeNode* FrontNode = Q.front();
            Q.pop();

            if(FrontNode) {
                if(FrontNode->left) {
                    Q.push(FrontNode->left);
                }
                
                if(FrontNode->right) {
                    Q.push(FrontNode->right);
                }

                temp.push_back(FrontNode->val);
            } else {
                if(!Q.empty()) {
                    Q.push(NULL);

                    Answer.push_back(temp);
                    temp.resize(0);
                }
            }
        }

        Answer.push_back(temp);
        return Answer;
    }
};