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
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        
        map <ListNode*, bool> visited;
        
        while(head != NULL) {
            if(visited[head] == true)
                return true;
            
            visited[head] = true;
            head = head->next;
        }
        
        return false;
    }
};