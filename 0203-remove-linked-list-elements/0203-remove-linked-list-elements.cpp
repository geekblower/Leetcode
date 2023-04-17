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
private:
    void deletePosition(ListNode* &head, int pos) {
        if(pos == 1) {
            ListNode* target = head;
            head = head->next;
            delete target;
            return;
        }

        ListNode* temp = head;

        while(temp!=NULL && pos>2) {
            temp = temp->next;
            pos--;
        }

        ListNode* target = temp->next;
        temp->next = target->next;
        delete target;
    }
    
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        int position = 1;

        while(temp != NULL) {
            if(temp->val == val) {
                temp = temp->next;
                deletePosition(head, position);
            } else {
                temp = temp->next;
                position++;
            }
        }

        return head;
    }
};