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
class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        
        while(head!=NULL) {
            len++;
            head = head->next;
        }
        
        return len;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int len = getLength(head);
        
        ListNode* left = head;
        ListNode* right = head;
        
        for(int i=1; i<k; i++)
            left = left->next;
        
        for(int i=0; i<len-k; i++)
            right = right->next;
        
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
        
        return head;
    }
};