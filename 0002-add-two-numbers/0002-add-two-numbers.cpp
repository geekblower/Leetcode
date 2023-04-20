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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void insertHead(ListNode* &head, int data) {
        ListNode* temp = new ListNode(data, head);
        head = temp;    
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = NULL;
        int carry = 0;

        while(l1!=NULL || l2!=NULL || carry!=0) {
            int val = 0;

            if(l1 != NULL) {
                val += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL) {
                val += l2->val;
                l2 = l2->next;
            }

            if(carry != 0) {
                val += carry;
            }

            insertHead(answer, val%10);
            carry = val / 10;
        }

        l1 = reverse(l1);
        l2 = reverse(l2);
        answer = reverse(answer);

        return answer;
    }
};