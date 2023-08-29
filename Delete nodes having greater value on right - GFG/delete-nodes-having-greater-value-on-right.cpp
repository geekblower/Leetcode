//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        
        while(curr != nullptr) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
    Node *compute(Node *head) {
        Node* new_head = reverse(head);
        Node* prev = new_head;
        Node* curr = new_head->next;
        
        int max = new_head->data;
        
        while(curr != nullptr) {
            if(curr->data < max) {
                Node* temp = curr;
                prev -> next = curr->next;
                curr = prev->next;
                delete temp;
            } else {
                max = curr-> data;
                prev = curr;
                curr = curr->next;
            }
        }
        
        return reverse(new_head);
    }
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends