/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL;
        Node* newTail = NULL;
        Node* curr = head;
        unordered_map<Node*, Node*> map;
        unordered_map<Node*, Node*> nodeMap;
        
        while(curr != NULL) {
            Node* temp = new Node(curr->val);
            nodeMap[curr] = temp;
            
            map[temp] = curr->random;
            
            if(newHead == NULL) {
                newHead = newTail = temp;
            } else {
                newTail->next = temp;
                newTail = temp;
            }
            
            curr = curr->next;
        }
        
        curr = newHead;
        while(curr != NULL) {
            curr->random = nodeMap[map[curr]];
            curr = curr->next;
        }
        
        return newHead;
    }
};