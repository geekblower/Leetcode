/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void solve(TreeNode* &root, vector<int> &arr, int left, int right) {
        if(left > right) {
            return;
        }

        int mid = left + (right-left)/2;
        root = new TreeNode(arr[mid]);

        solve(root->left, arr, left, mid-1);
        solve(root->right, arr, mid+1, right);
    }

    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = NULL;
        vector<int> arr;

        while(head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }

        solve(root, arr, 0, arr.size()-1);
        return root;
    }
};