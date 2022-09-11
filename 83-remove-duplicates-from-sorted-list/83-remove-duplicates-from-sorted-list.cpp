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
    void removeElement(ListNode* &head, int pos) {
        ListNode* temp = head;
        int count = 1;
        
        while(count < pos-1) {
            temp = temp->next;
            count++;
        }
        
        ListNode* targetNode = temp->next;
        temp->next = targetNode->next;
        delete targetNode;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL)
            return head;
        
        int num = head->val;
        ListNode* temp = head->next;
        int pos = 2;
        
        while(temp != NULL) {
            if(temp->val == num) {
                temp = temp->next;
                removeElement(head, pos);
            } else {
                num = temp->val;
                temp = temp->next;
                pos++;
            }
        }
        
        return head;
    }
};