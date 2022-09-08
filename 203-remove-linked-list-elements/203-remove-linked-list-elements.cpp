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
    void deleteNodeByPosition(ListNode* &head, int position) {
        if(position == 1) {
            ListNode* current = head;
            head = current->next;
            delete current;
            return;
        }

        ListNode* tempNode = head;
        int count = 1;

        while(count < position-1) {
            tempNode = tempNode->next;
            count++;
        }

        ListNode* current = tempNode->next;
        
        if(current != NULL)
            tempNode->next = current->next;

        delete current;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        
        ListNode* temp = head;
        int pos = 1;
        
        while(temp != NULL) {
            if(temp->val == val) {
                temp = temp->next;
                deleteNodeByPosition(head, pos);
            } else {
                temp = temp->next;
                pos++;
            }
        }
        
        return head;
    }
};