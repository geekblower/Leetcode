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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        
        stack<int> stk;
        ListNode *temp=head;
        
        while(temp != NULL) {
            stk.push(temp->val);
            temp = temp->next;
        }
        
        temp=head;
        
        while(temp != NULL){
            temp->val = stk.top();
            stk.pop();
            temp = temp->next;
        }
        /*
        
        ListNode* temp = head->next;
        head->next = NULL;
        
        while(temp->next != NULL) {
            ListNode* currentNode = temp;
            currentNode->next = head;
            head = temp;
        }
        */
        return head;
        
    }
};