/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    stack<Node*>s;
    inline void doit(Node* root){
        if(s.size()==0)
            root->next = NULL;
        else {
            root->next = s.top();
            s.pop();
        }
        
        if(root->left!=NULL) {
            doit(root->right);
            doit(root->left);
        }
        s.push(root);    
    }
    
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        
        doit(root);
        
        return root;
    }
};