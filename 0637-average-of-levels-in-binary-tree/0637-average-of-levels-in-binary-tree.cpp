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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> Answer;

        if(root == NULL) {
            return Answer;
        }

        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);
        long long levelSum = 0;
        int nodeCount = 0;

        while(!Q.empty()) {
            TreeNode* FrontNode = Q.front();
            Q.pop();

            if(FrontNode == NULL) {
                double temp = (double) levelSum / nodeCount;
                Answer.push_back(temp);

                levelSum = 0;
                nodeCount = 0;

                if(!Q.empty()) {
                    Q.push(NULL);
                }
            } else {
                levelSum += FrontNode->val;
                nodeCount++;

                if(FrontNode->left)
                    Q.push(FrontNode->left);

                if(FrontNode->right)
                    Q.push(FrontNode->right);
            }
        }

        return Answer;
    }
};