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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        
        while(head!=NULL && head->next!=NULL && head->val == head->next->val) {
            while(head!=NULL && head->next!=NULL && head->val==head->next->val)
                head = head->next;
            
            if(head!=NULL)
                head = head->next;
            else
                return head;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL && curr->next!=NULL) {
            if(curr->val == curr->next->val) {
                while(curr!=NULL && prev->next->val==curr->val) {
                    curr = curr->next;
                }
                
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};
