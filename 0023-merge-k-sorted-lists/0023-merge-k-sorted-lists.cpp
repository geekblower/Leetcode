/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/

class compare {
public:
    bool operator () (ListNode* A, ListNode* B) {
        return (A->val) > (B->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        for(int i=0; i<lists.size(); i++) {
            if(lists[i] != NULL) {
                minHeap.push(lists[i]);
            } 
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(minHeap.size() > 0) {
            ListNode* Top = minHeap.top();
            minHeap.pop();

            if(Top->next != NULL) {
                minHeap.push(Top->next);
            }

            if(head == NULL) {
                head = tail = Top;
            } else {
                tail->next = Top;
                tail = Top;
            }
        }

        return head;
    }
};