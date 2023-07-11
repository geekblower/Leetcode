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
    int minVal(TreeNode* root) {
        int mini = -1;

        while(root != NULL) {
            mini = root->val;
            root = root->left;
        }

        return mini;
    }

    TreeNode* deleteBST(TreeNode* root, int key) {
        if(root == NULL) {
            return root;
        }

        if(root->val == key) {
            // 0 Child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // 1 Child - Left
            if(root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // 1 Child - Right
            if(root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->left != NULL && root->right != NULL) {
                int mini = minVal(root->right);
                root->val = mini;
                root->right = deleteBST(root->right, mini);
                return root;
            }
        }

        if(root->val > key) {
            root->left = deleteBST(root->left, key);
        } else {
            root->right = deleteBST(root->right, key);
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* answer = deleteBST(root, key);
        return answer;
    }
};