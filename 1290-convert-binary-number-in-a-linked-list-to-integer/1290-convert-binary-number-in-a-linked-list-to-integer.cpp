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
    
    int getDecimalValue(ListNode* head) {
        int len = getLength(head);
        int answer = 0;
        
        while(head!=NULL) {
            if(head->val == 1) {
                answer += pow(2, len-1);
            }
            
            head = head->next;
            len--;
        }
        
        return answer;
    }
};