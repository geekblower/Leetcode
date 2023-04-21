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
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        ListNode* answer = new ListNode(-1);
        ListNode* temp = answer;

        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
                temp->next = NULL;
            } else {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
                temp->next = NULL;
            }
        }

        if(list1 != NULL) {
            temp->next = list1;
        }

        if(list2 != NULL) {
            temp->next = list2;
        }

        return answer->next;
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    
    ListNode* mergeSort(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }

        ListNode* mid = findMiddle(head);
        
        ListNode* list1 = head;
        ListNode* list2 = mid->next;
        mid->next = NULL;

        list1 = mergeSort(list1);
        list2 = mergeSort(list2);

        ListNode* answer = mergeList(list1, list2);

        return answer;
    }

public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};