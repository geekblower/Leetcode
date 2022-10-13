/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return head;
        
        map <ListNode*, bool> visited;
        
        while(head != NULL) {
            if(visited[head] == true)
                return head;
            
            visited[head] = true;
            head = head->next;
        }
        
        return head;
    }
};