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
    ListNode* middleNode(ListNode* head) {
        ListNode* mid = NULL;
        ListNode* temp = head;
        
        while(head!=NULL && head->next!=NULL) {
            head = head->next->next;
            mid = temp;
            temp = temp->next;
        }
        
        return mid;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return NULL;
        }
        
        ListNode* mid = middleNode(head);
        
        ListNode* temp = mid->next;
        mid->next = temp->next;
        delete(temp);
        
        return head;
    }
};